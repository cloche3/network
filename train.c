#include <stdio.h>
#include <stddef.h>

#define RED   (0)
#define GREEN (1)

struct train_info {
  int number;                   /* 列車番号 */
  struct block_info* dest;      /* 列車の終着駅を出口とする区間 */
};

struct block_info {
  struct train_info* train;     /* 区間内にいる列車 */
  struct block_info* next[2];
  int signal;                   /* 信号機の色 */
};

void set_signals(struct block_info[], int);
void proceed(struct block_info[], int);
int find_block(struct block_info*, struct block_info*);
void start(struct block_info[], int);
void block_state_print(struct block_info[], int); /* 自作：区間の情報を表示する */

void set_signals(struct block_info blocks[], int nblocks) {
  int i;
  struct block_info* block;
  for (i = 0; i < nblocks; i++) {
    block = &blocks[i];
    if (block->train == NULL) {
      block->signal = GREEN;
    }
    else {
      block->signal = RED;
    }
  }
}  

void proceed(struct block_info blocks[], int nblocks) {
  int i, j;
  struct block_info* block;
  for (i = nblocks - 1; i >= 0; i--) {
    block = &blocks[i];
    if (block->train == NULL) {
      continue;
    }
    if (block == block->train->dest) { /* 終点なら取り除く */
      block->train = NULL;
      continue;
    }
    for (j = 0; j < 2; j++) {
      if (block->next[j] == NULL) {
        continue;
      }
      if (block->next[j]->signal == RED) {
        continue;
      }
      if (find_block(block->next[j], block->train->dest) == 1) {
        block->next[j]->train = block->train;
        block->next[j]->signal = RED;
        block->train = NULL;
        break;
      }
    }
  }
}

int find_block(struct block_info* block, struct block_info* dest) {
  int i;
  if (block == dest) {
    return 1;
  }
  for (i = 0; i < 2; i++) {
    if (block->next[i] == NULL) {
      continue;
    }
    if (find_block(block->next[i], dest) == 1) {
      return 1;
    }
  }
  return 0;
}

void start(struct block_info blocks[], int nblocks) {
  int i;
  set_signals(blocks, nblocks);
  printf("----- 初期状態 -----\n");
  block_state_print(blocks, nblocks);
  for (i = 0; i < 4; i++) {
    proceed(blocks, nblocks);
    set_signals(blocks, nblocks);
    printf("----- 進行%d回目 -----\n", i+1);
    block_state_print(blocks, nblocks);
  }
}

void block_state_print(struct block_info blocks[], int nblocks) {
  int i;
  for (i = 0; i < nblocks; i++) {
    printf("区間%d : %s : ", i, (blocks[i].signal == RED ? "赤" : "緑"));
    if (blocks[i].train != NULL) {
      printf("列車%d\n", blocks[i].train->number);
    }
    else {
      printf("  - \n");
    }
  }
}

int main(void) {
  struct block_info blocks[9];
  struct train_info trains[5] = {{ 0, &blocks[8] },
                                 { 1, &blocks[5] },
                                 { 2, &blocks[6] },
                                 { 3, &blocks[5] },
                                 { 4, &blocks[8] }};
  blocks[0].train = &trains[4];
  blocks[0].next[0] = &blocks[2]; blocks[0].next[1] = NULL;
  blocks[1].train = &trains[3];
  blocks[1].next[0] = &blocks[2]; blocks[1].next[1] = NULL;
  blocks[2].train = NULL;
  blocks[2].next[0] = &blocks[3]; blocks[2].next[1] = NULL;
  blocks[3].train = &trains[2];
  blocks[3].next[0] = &blocks[4]; blocks[3].next[1] = &blocks[7];
  blocks[4].train = &trains[1];
  blocks[4].next[0] = &blocks[5]; blocks[4].next[1] = &blocks[6];
  blocks[5].train = NULL;
  blocks[5].next[0] = NULL; blocks[5].next[1] = NULL;
  blocks[6].train = NULL;
  blocks[6].next[0] = NULL; blocks[6].next[1] = NULL;
  blocks[7].train = NULL;
  blocks[7].next[0] = &blocks[8]; blocks[7].next[1] = NULL;
  blocks[8].train = &trains[0];
  blocks[8].next[0] = NULL; blocks[8].next[1] = NULL;
  
  start(blocks, 9);
  
  return 0;
}
