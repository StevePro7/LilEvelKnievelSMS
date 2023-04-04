REM bank54
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank54 bank54 54

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK54 bank54.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
