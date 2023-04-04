REM bank21
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank21 bank21 21

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK21 bank21.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
