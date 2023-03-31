REM bank12
@echo off

cd ..
cd banks

::"C:/Program Files/SDCC/bin/folder2c" bank12 bank12 12

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK12 bank12.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
