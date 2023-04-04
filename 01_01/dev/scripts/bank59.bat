REM bank59
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank59 bank59 59

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK59 bank59.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
