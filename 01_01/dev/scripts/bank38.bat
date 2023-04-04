REM bank38
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank38 bank38 38

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK38 bank38.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
