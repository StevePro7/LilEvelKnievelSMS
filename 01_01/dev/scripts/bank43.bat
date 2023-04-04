REM bank43
@echo off

cd ..
cd banks

"C:/Program Files/SDCC/bin/folder2c" bank43 bank43 43

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK43 bank43.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts
