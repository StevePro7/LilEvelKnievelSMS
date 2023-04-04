REM bank45
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank45 bank45 45

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK45 bank45.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
