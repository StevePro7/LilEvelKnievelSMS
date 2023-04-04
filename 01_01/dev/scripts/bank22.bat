REM bank22
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank22 bank22 22

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK22 bank22.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
