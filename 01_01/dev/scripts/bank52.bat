REM bank52
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank52 bank52 52

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK52 bank52.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
