@echo off
setlocal

set timer_path=..\
set cl10_path=..\
set checker_name=ch_olympiad
set task_name=Районная олимпиада по информатике
set task_code=olympiad
set time_limit=2000
set memory_limit=65536
set balls_per_test=2
set input_file=input.txt
set output_file=output.txt

if %1. ==. goto test_all
call :test0 %1
goto :eof

:test_all
for %%i in (sources\*.*) do call :test0 %%i
goto :eof

:test0

set java=0
if %1. == . goto noparm
if exist results\%~n1.res del results\%~n1.res
echo Task: %task_name% >results\%~n1.res
echo Program to test: %~n1 >>results\%~n1.res
echo ................ >>results\%~n1.res 
echo Program to test: %~n1

if exist sources\%~n1.dpr goto comp_dpr
if exist sources\%~n1.pas goto comp_pas
if exist sources\%~n1.gpp goto comp_gpp
if exist sources\%~n1.g11 goto comp_g11
if exist sources\%~n1.cpp goto comp_cpp
if exist sources\%~n1.java goto comp_java

:no_source
echo No source file found! >>results\%~n1.res
echo No source file found!
goto :eof

:comp_java
set java=1
copy sources\%~n1.java . >nul
javac %~n1.java
del %~n1.java >nul
if exist %~n1.class goto testing
goto no_exe

:comp_dpr
copy sources\%~n1.dpr . >nul
dcc32 -CC -$O+ %~n1.dpr >>results\%~n1.res
:ppc386 -O2 %~n1.pas >>results\%~n1.res
del %~n1.dpr >nul
if exist %~n1.exe goto testing
goto no_exe

:comp_pas
copy sources\%~n1.pas . >nul
:ppc386 -So -O2 %~n1.pas >>results\%~n1.res
ppc386 -O2 %~n1.pas >>results\%~n1.res
del %~n1.pas >nul
if exist %~n1.exe goto testing
goto no_exe

:comp_cpp
copy sources\%~n1.cpp . >nul
:g++ -O2 -o %~n1 %~n1.cpp >>results\%~n1.res 2>&1
:call ..\cl8 %~n1.cpp >>results\%~n1.res 2>&1
call %cl10_path%cl10 %~n1.cpp >>results\%~n1.res 2>&1
del %~n1.cpp >nul
if exist %~n1.exe goto testing
goto no_exe

:comp_gpp
copy sources\%~n1.gpp .\*.cpp >nul
g++ -O2 -o %~n1 %~n1.cpp >>results\%~n1.res 2>&1
del %~n1.cpp >nul
if exist %~n1.exe goto testing
goto no_exe

:comp_g11
copy sources\%~n1.g11 .\*.cpp >nul
g++ -O2 --std=c++11 -o %~n1 %~n1.cpp >>results\%~n1.res 2>&1
del %~n1.cpp >nul
if exist %~n1.exe goto testing
goto no_exe

:no_exe
if %java% == 0 (
 echo The executable file isn't found!
 echo The executable file isn't found! >>results\%~n1.res
) else (
 echo The Java class file isn't found!
 echo The Java class file isn't found! >>results\%~n1.res
)
goto :eof

:testing
if exist %~n1.ow del %~n1.ow 
if exist %~n1.obj del %~n1.obj
if exist %~n1.o del %~n1.o


for %%i in (*.i) do call :test_one %%~ni %~n1 %task_code%


if exist %~n1.exe del %~n1.exe >nul
if exist *.class del *.class >nul

goto :eof
:noparm
echo Usage: test filename 
echo Filename can be with or without extension!
echo The compiler depends on the source file extension:
echo    .dpr        - Borland Delphi 7 
echo    .pas        - Free Pascal 2.6
echo    .gpp        - MinGV g++ 4.8.1
echo    .g11        - MinGV g++ 4.8.1 with standart C++11
echo    .cpp        - Microsoft Visual Studio 2010
echo    .java       - Java SDK (1.5.0 or more)
goto :eof

:test_one

@echo off
@echo Test %1
@echo ******************************************** >>results\%2.res
@echo Test %1 >>results\%2.res
copy %1.i %input_file% >nul

if %java% == 0 (
 %timer_path%timer %2.exe %time_limit% %memory_limit% >>results\%2.res
) else (
 java %2 2>aaa.aaa
) 
if errorlevel 1 goto bad_run 

:ren %output_file% %1.o >nul
if exist checker.in del checker.in
echo 1 > checker.in
echo %input_file% >> checker.in
echo 1 >> checker.in
echo %1.o >> checker.in
echo %output_file% >> checker.in
echo 999 >> checker.in
echo %3 >> checker.in
echo %1 >> checker.in
echo %balls_per_test% >> checker.in
echo 1 >> checker.in
%checker_name%
copy results\%2.res+checker.out results\%2.res >nul
goto clean

:bad_run
echo Everything fail!
:clean
if exist checker.in del checker.in
if exist checker.out del checker.out
if exist %input_file% del %input_file%
if exist %output_file% del %output_file%
if exist aaa.aaa del aaa.aaa

:eof
endlocal
