REM bank28
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank28 bank28 28

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK28 bank28.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
