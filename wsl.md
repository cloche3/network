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

（追記）良く探したら最初にブックマークして埋もれた資料を発見。こっちの方法が環境に合う
>[Windows10でDockerを使うための最短コースをご案内](https://www.orangeitems.com/entry/2019/01/10/143859)

しかし上記の問題発生。WSL2が来年の春に公開されるので，今回はDocker+ WSLを試さなかった。

## fish plugin
---
WSLにfishいれたのでplaginも入れる。

[ターミナルが100倍楽しくなるfish](https://blog.mamansoft.net/2017/10/15/enjoy-fish/)

[WSLとHyperを利用した環境を整える](https://matcha-choco010.net/2018/06/30/wsl%E3%81%A8hyper%E3%82%92%E5%88%A9%E7%94%A8%E3%81%97%E3%81%9F%E7%92%B0%E5%A2%83%E3%82%92%E6%95%B4%E3%81%88%E3%82%8B/)

[oh-my-fish は古い！fisherman で置き換えられる。](https://futurismo.biz/archives/6079)

[fish shellが結構良かった話](https://qiita.com/hennin/items/33758226a0de8c963ddf)

```Bash
\*fisher(fisherman install)
curl https://git.io/fisher --create-dirs -sLo ~/.config/fish/functions/fisher.fish

\* plagin　追加方法
fisher add <plagin name>

oh-my-fish/theme-bobthefish \*ステータス表示

jethrokuan/fzf \*いろいろキーバインドする(ちゃんと入ってない？設定必須)

decors/fish-ghq　\* ghp(?)のラッパー。git cloneを一括管理
```
動かないものもあるのでちゃんと整備する

wsl バージョン確認
```
wsl --list --verbose
wsl -l -v \* 省略
```
バージョン変更
```
wsl --set-version <ディストリビューション名> <1or2>
wsl --set-default-version 2 \* 既存のアーキテクチャ変更（新しくインストールされるやつがwsl2に）
```
[wslインストールガイド](https://docs.microsoft.com/ja-jp/windows/wsl/install-win10)