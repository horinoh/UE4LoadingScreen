# UE4LoadingScreen

## 参考 Cf.
* https://wiki.unrealengine.com/Loading_Screen#Overview?t=1&cn=ZmxleGlibGVfcmVjcw%3D%3D&refsrc=email&iid=c7b453738bc8452abff43598a7d0a40b&fl=4&uid=3310728056&nid=244+272699400
* https://wiki.unrealengine.com/Global_Fade_In_out

## やったこと What's done
* "MoviePlayer" モジュールを追加した Add "MoviePlayer" Module
* GameInstanceを作成した Create GameIsntace

## 実行 Execute
* [パッケージ化する (Do packaging)](https://github.com/horinoh/UE4DedicatedServer/tree/master/Document/Packaging)
* PIEでは「ローディング画面」に行かないので、(Package/WindowsNoEditor/UE4LoadingScreen.exe を起動する Because PIE will not go loading screen, execute Package/WindowsNoEditor/UE4LoadingScreen.exe)
* マップの移動はコンソールコマンド(@)で open GreenMap のようにする (From console command, "open GreenMap")
* マップ移動中に「ローディング画面」が出ればOK (On map transition, loading screen will appear)