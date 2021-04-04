echo off
rem https://www.cnblogs.com/markleaf/p/7781127.html
rem warning: C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失。
del *.obj
del *.exe
cl  /EHsc   my.cpp mfc.cpp
del *.obj