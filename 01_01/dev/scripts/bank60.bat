REM bank60
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank60 bank60 60

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK60 bank60.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
