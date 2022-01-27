@echo off
:loop
makeb.exe > in.txt
B.exe < in.txt > B.txt
bdfs.exe < in.txt > bdfs.txt

fc B.txt bdfs.txt
if not errorlevel 1 goto loop
pause