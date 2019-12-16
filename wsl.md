# WSL

ターミナル内で使うWSLについてLinux環境を扱うことができることしか知らずに入れている。2020春にWSL2が標準開発環境で登場するのでこれを期に調べてみる。ついでにmarkdown file test
## カーネルモード

仮想環境は大まかに分けてVMwareのようなホスト型、Hyper-Vのようなハイパーバイザー型、Dockerが扱うコンテナ型がある。
wslはDockerとほぼ同じらしい。ちなみにwindow10 home はHyper-Vが無いので現状、Docker for windowsは使えず、Docker ToolboxをVirtualBoxで操作することになる。
ここで気になったことがwsl上でDocker動かせないかと言うことである。結論として「一応は」動くらしい。
## 参考URL
>[WSL + Ubuntu で Docker が動くっ！動くぞコイツッ！](https://qiita.com/koinori/items/78a946fc74452af9afba)

>[Windows Subsystem for Linux(WSL)で Docker を利用する](https://simplestar-tech.hatenablog.com/entry/2019/10/14/101551)

>[Windows Subsystem for Linux（Hyper-Vなし）でDockerを動かす](https://www.nuits.jp/entry/docker-on-wsl)

春まで待つことが無難？

更新用コマンド

```Bash
$sudo apt update
$sudo apt full-upgrade -y
$sudo apt autoremove
```

導入(18.04.3では動かない模様)
```Bash
$sudo apt install -y docker.io
/*再起動して
$sudo cgroupfs-mount
$sudo service docker start
```

Cannot connect to the Docker daemonと表示されるのでそこをなんとかしなかればならない（Client自体は存在する）

## fish plugin
WSLにfishいれたのでplaginも入れよう。

[ターミナルが100倍楽しくなるfish](https://blog.mamansoft.net/2017/10/15/enjoy-fish/)