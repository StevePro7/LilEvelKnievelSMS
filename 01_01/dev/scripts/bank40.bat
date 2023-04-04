REM bank40
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank40 bank40 40

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK40 bank40.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
