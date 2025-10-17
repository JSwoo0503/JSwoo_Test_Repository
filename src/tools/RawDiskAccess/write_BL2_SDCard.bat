@echo off

rem NORMAL BOOT
RawDiskAccess.exe WRITE E 0 ..\..\build\DebugRel_BL2\APACHE6_BL2_aarch32_AP60.bin
rem RawDiskAccess.exe WRITE E 0 ..\..\build/DebugRel_BL2/APACHE6_BL2_aarch64_AP60.bin

rem SECURE  BOOT
rem RawDiskAccess.exe WRITE E 0 ..\..\build\DebugRel_BL2\APACHE6_BL2_aarch32_SECURE_AP60.bin

pause
