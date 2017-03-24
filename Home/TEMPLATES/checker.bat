echo off
:penisbenis
python gen.py
python main.py
1.exe
check.exe
if %errorlevel% == 0 (
	goto :penisbenis
)
pause
