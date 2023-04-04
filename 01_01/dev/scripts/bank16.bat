REM bank16
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank16 bank16 16

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK16 bank16.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
