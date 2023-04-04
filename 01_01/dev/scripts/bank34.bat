REM bank34
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank34 bank34 34

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK34 bank34.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
