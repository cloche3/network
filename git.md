# git

>[サルでもわかるgit](https://backlog.com/ja/git-tutorial/)

>[画像による簡易的なgitについての説明](https://twitter.com/098ra0209/status/1163424568544907265?s=12)

まずGitHubに登録

今回インストールするのはLiunxとwindowsにする。後述するプロキシ設定をすると家でgitが扱えない。（ローカルリポジトリごとに設定、または複数端末あるならいいが）

[windowsコンソールインストール](https://git-scm.com)

Ubuntu
```Bush
$ sudo apt-get install git-all
$ git --version  \\確認用
```

# 初期設定
```
$ git config --global user.name "<ユーザ名>"
$ git config --global user.email "<メールアドレス>"
$ git config --global http://wwwproxy.kanazawa-it.ac.jp:8080/
$ git config --global https://wwwproxy.kanazawa-it.ac.jp:8080/
```
--globalを抜くとローカルリポジトリごとに設定できる。

設定削除方法
```
$ git config --global --unset http://wwwproxy.kanazawa-it.ac.jp:8080/
$ git config --unset キー名
```

## 確認用
```
$ git config --list
$ git config キー名
```
>[gitconfig説明](https://qiita.com/shionit/items/fb4a1a30538f8d335b35)

# 作成

参考(https://employment.en-japan.com/engineerhub/entry/2017/01/31/110000)

```
$ mkdir git
$ cd git
$ git clone リポジトリurl
$ cd リポジトリ名
```

ブランチ
```
$ git branch ブランチ名
$ git checkout　ブランチ名
$ git branch　\\ブランチ確認
```
コミット
```
$ git add ファイル名
$ git status　\\コミット内容確認
$ git commit -m "コメント"
\\ 以下省略
$ git commit -a -m "コメント"
```

プッシュ
```
$ git push origin ブランチ名
```

GitHubのページを開いてプルリクエストとかいろいろして終了

更新
```
$ git checkout master
$ git pull
$ git branch -d ブランチ名　\\ブランチ削除
$ git branch -D ブランチ名 \\強制
```

## GUI

[VSCodeを使う](https://qiita.com/y-tsutsu/items/2ba96b16b220fb5913be)

[SourceTree](https://www.sourcetreeapp.com)

[fork（試用系）](https://git-fork.com)

あとGitHub Desktop