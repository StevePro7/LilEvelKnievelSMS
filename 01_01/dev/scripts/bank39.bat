REM bank39
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank39 bank39 39

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK39 bank39.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
