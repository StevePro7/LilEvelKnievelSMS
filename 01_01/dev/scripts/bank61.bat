REM bank61
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank61 bank61 61

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK61 bank61.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
