@echo off
setlocal

set CC=tcc

reg Query "HKLM\Hardware\Description\System\CentralProcessor\0" | find /i "x86" > NUL && (set ARCH=x86) || (set ARCH=x64)

set TCC=C:\Users\wjbr\scoop\apps\tcc\current\tcc

set PATH=%PATH%;%TCC%\lib\%ARCH%

%CC% -I%TCC%\libtcc -L%TCC% -llibtcc -run runtime.c

