REM bank35
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank35 bank35 35

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK35 bank35.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
