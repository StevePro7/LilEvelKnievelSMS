@echo off
REM echo Generate levels

cd ..
cd banks
::cd bank2

:: Tiles
::"C:/SEGA/bmp2tile043/bmp2tile.exe" raw/bggame_tiles.png -savetiles "bggame_tiles (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 0 -savetilemap "bggame_tiles (tilemap).bin" -savepalette "bggame_tiles (palette).bin" -fullpalette -exit
::"C:/SEGA/bmp2tile043/bmp2tile.exe" raw/splash_tiles.png -savetiles "splash_tiles (tiles).psgcompr" -removedupes -nomirror -planar -tileoffset 0 -savetilemap "splash_tiles (tilemap).bin" -savepalette "splash_tiles (palette).bin" -fullpalette -exit
::"C:/SEGA/bmp2tile043/bmp2tile.exe" raw/sprite_tiles.png -savetiles "sprite_tiles (tiles).psgcompr" -noremovedupes -nomirror -planar -tileoffset 0 -savepalette "sprite_tiles (palette).bin" -fullpalette  -spritepalette -exit

::cd ..
::folder2c bank2 bank2 2

sdcc --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK2 bank2.c

del *.asm > nul; del *.lst > nul; del *.sym > nul

cd ..
cd scripts