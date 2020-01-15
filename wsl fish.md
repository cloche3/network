# fish Shell
前回terminusでfish_configを使って設定を変更しようとしたがなにかエラーが出たものの見えず、シャットダウンされてしまうため原因を突き止めにくかった。そこで前々から入れていたが使っていなかったWSlttyを使用しエラーを確認した。確認するとただ単にファイルに設定のためのhtmlファイルが無いだけであった。またWslttyでfishを起動すると標準のフォントでは文字化けを起こすので「cica」を使った。

>[Wsltty-Github](https://github.com/mintty/wsltty)

>[cica-Github](https://github.com/miiton/Cica)

今回はファイル設定を変更する際Visual Studio Codeで修正するため拡張機能である「Remote - WSl」使用した。

今現在問題としているのはfisher plaginのひとつであるfzfが機能通りに動かないことである。具体的に言えばctrl+Gで起動するようだがエラーが出てしまい使えないことである。原因を調べてみると「~/.config/fish/functions/__ghq_repository_search.fish (line 15):」にあるようだ。