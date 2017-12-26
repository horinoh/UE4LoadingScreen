# UE4LoadingScreen

## 参考
* https://wiki.unrealengine.com/Loading_Screen#Overview?t=1&cn=ZmxleGlibGVfcmVjcw%3D%3D&refsrc=email&iid=c7b453738bc8452abff43598a7d0a40b&fl=4&uid=3310728056&nid=244+272699400
* https://wiki.unrealengine.com/Global_Fade_In_out

## やったこと
* "MoviePlayer" モジュールを追加した
* GameInstanceを作成した

## 実行
* [パッケージ化する](https://github.com/horinoh/UE4DedicatedServer/tree/master/Document/Packaging)
* PIEでは「ローディング画面」に行かないので、Package/WindowsNoEditor/UE4LoadingScreen.exe を起動する
* マップの移動はコンソールコマンド(@)で open GreenMap のようにする
* マップ移動中に「ローディング画面」が出ればOK