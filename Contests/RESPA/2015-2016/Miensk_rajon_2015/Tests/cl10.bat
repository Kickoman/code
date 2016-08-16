@echo off
call "c:\Program Files\Microsoft Visual Studio 10.0\VC\VCVARSALL.BAT" 
cl -EHsc /O2 /TP /D_CRT_SECURE_NO_DEPRECATE %~n1.cpp
