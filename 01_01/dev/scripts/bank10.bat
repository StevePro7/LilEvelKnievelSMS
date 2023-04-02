REM bank10
@echo off

cd ..
cd banks

::"C:/Program Files/SDCC/bin/folder2c" bank10 bank10 10

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK10 bank10.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
