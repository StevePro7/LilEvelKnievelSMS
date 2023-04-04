REM bank3
@echo off

cd ..
cd banks
cd bank3

:: Tiles
"C:/SEGA/bmp2tile043/bmp2tile.exe" raw/titles_tiles.png -savetiles "titles_tiles (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 0 -savetilemap "titles_tiles (tilemap).bin" -savepalette "titles_tiles (palette).bin" -fullpalette -exit

cd ..
folder2c bank3 bank3 3

"C:/Program Files/SDCC/bin/sdcc" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK3 bank3.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts