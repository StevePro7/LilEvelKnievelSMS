REM bank51
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank51 bank51 51

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK51 bank51.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
