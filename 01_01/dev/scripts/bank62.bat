REM bank62
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank62 bank62 62

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK62 bank62.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
