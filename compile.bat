@echo off
cd /d "C:\Users\User\Documents\GitHub\Algorithmization-and-Programming-UI6-2026-27"
call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x64
cl /EHsc /std:c++17 /I. main.cpp Homeworks-S1\HW1-V8-S1.cpp Homeworks-S1\HW2-V8-S1.cpp Homeworks-S1\HW3-V8-S1.cpp Homeworks-S1\maxim.cpp /Fe:outDebug.exe
pause