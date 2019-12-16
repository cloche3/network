# WSL

ターミナル内で使うWSLについてLinux環境を扱うことができることしか知らずに入れている。2020春にWSL2が標準開発環境で登場するのでこれを期に調べてみる。ついでにmarkdown file test
## カーネルモード

仮想環境は大まかに分けてVMwareのようなホスト型、Hyper-Vのようなハイパーバイザー型、Dockerが扱うコンテナ型がある。
wslはDockerとほぼ同じらしい。ちなみにwindow10 home はHyper-Vが無いので現状、Docker for windowsは使えず、Docker ToolboxをVirtualBoxで操作することになる。
ここで気になったことがwsl上でDocker動かせないかと言うことである。結論として「一応は」動くらしい。
## 参考URL
><https://qiita.com/koinori/items/78a946fc74452af9afba>
><https://qiita.com/tettsu__/items/85c96850d187e4386c24>
><https://simplestar-tech.hatenablog.com/entry/2019/10/14/101551>
><https://www.nuits.jp/entry/docker-on-wsl>

## fish plugin
WSLにfishいれたので　plaginも入れよう。