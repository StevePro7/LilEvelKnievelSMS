@echo off

:: Time build START
:: Reference: https://stackoverflow.com/questions/673523/how-do-i-measure-execution-time-of-a-command-on-the-windows-command-line
set _time=%time: =0%
set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
set /a _started=_hours*60*60*100+_min*60*100+_sec*100+_cs

:: Compile
cd banks
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c --no-std-crt0 -mz80 --Werror --opt-code-speed --constseg BANK15 fixedbank.c
cd ..

cd devkit
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 _sms_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 _snd_manager.c
cd ..

cd engine
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 asm_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 audio_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 collision_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 command_manager.c 
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 content_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 cartoon_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 debug_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 enum_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 font_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 game_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 global_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 graphics_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 hack_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 input_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 level_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 player_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 riff_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 sample_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 screen_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 scroll_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 sprite_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 storage_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 tile_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 timer_manager.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 util_manager.c
cd ..

cd object
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-size --peep-file ../peep-rules.txt --std-c99 audio_object.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-size --peep-file ../peep-rules.txt --std-c99 command_object.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-size --peep-file ../peep-rules.txt --std-c99 game_object.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-size --peep-file ../peep-rules.txt --std-c99 hack_object.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-size --peep-file ../peep-rules.txt --std-c99 level_object.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-size --peep-file ../peep-rules.txt --std-c99 player_object.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-size --peep-file ../peep-rules.txt --std-c99 riff_object.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-size --peep-file ../peep-rules.txt --std-c99 scroll_object.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-size --peep-file ../peep-rules.txt --std-c99 storage_object.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-size --peep-file ../peep-rules.txt --std-c99 tile_object.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-size --peep-file ../peep-rules.txt --std-c99 timer_object.c
cd ..

cd screen
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 beat_screen.c
"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 begin_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 boss_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 cont_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 dead_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 demo_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 diff_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 func_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 init_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 intro_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 level_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 load_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 none_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 option_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 over_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 pass_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 play_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 ready_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 record_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 repeat_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 splash_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 start_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 test_screen.c
::"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file ../peep-rules.txt --std-c99 title_screen.c
cd ..

"C:/Program Files/SDCC/bin/sdcc.exe" --debug -c -mz80 --opt-code-speed --peep-file peep-rules.txt --std-c99 main.c


:: Time build -END- 
set _time=%time: =0%
set /a _hours=100%_time:~0,2%%%100,_min=100%_time:~3,2%%%100,_sec=100%_time:~6,2%%%100,_cs=%_time:~9,2%
set /a _duration=_hours*60*60*100+_min*60*100+_sec*100+_cs-_started
set /a _hours=_duration/60/60/100,_min=100+_duration/60/100%%60,_sec=100+(_duration/100%%60%%60),_cs=100+_duration%%100
echo.
echo Time taken: %_sec:~-2%.%_cs:~-2% secs
echo.


:: Link
"C:/Program Files/SDCC/bin/sdcc.exe" --debug  -o output.ihx --Werror --opt-code-speed -mz80 --no-std-crt0 --data-loc 0xC000 ^
../crt0/crt0_sms.rel main.rel ^
-Wl-b_BANK2=0x8000  -Wl-b_BANK3=0x8000  -Wl-b_BANK4=0x8000  -Wl-b_BANK5=0x8000  -Wl-b_BANK6=0x8000  -Wl-b_BANK7=0x8000  -Wl-b_BANK8=0x8000  -Wl-b_BANK9=0x8000 ^
-Wl-b_BANK10=0x8000 -Wl-b_BANK11=0x8000 -Wl-b_BANK12=0x8000 -Wl-b_BANK13=0x8000 -Wl-b_BANK14=0x8000 -Wl-b_BANK15=0x8000 ^
-Wl-b_BANK16=0x8000 -Wl-b_BANK17=0x8000 -Wl-b_BANK18=0x8000 -Wl-b_BANK19=0x8000 -Wl-b_BANK20=0x8000 -Wl-b_BANK21=0x8000 -Wl-b_BANK22=0x8000 -Wl-b_BANK23=0x8000 ^
-Wl-b_BANK24=0x8000 -Wl-b_BANK25=0x8000 -Wl-b_BANK26=0x8000 -Wl-b_BANK27=0x8000 -Wl-b_BANK28=0x8000 -Wl-b_BANK29=0x8000 -Wl-b_BANK30=0x8000 -Wl-b_BANK31=0x8000 ^
-Wl-b_BANK32=0x8000 -Wl-b_BANK33=0x8000 -Wl-b_BANK34=0x8000 -Wl-b_BANK35=0x8000 -Wl-b_BANK36=0x8000 -Wl-b_BANK37=0x8000 -Wl-b_BANK38=0x8000 -Wl-b_BANK39=0x8000 ^
-Wl-b_BANK40=0x8000 -Wl-b_BANK41=0x8000 -Wl-b_BANK42=0x8000 -Wl-b_BANK43=0x8000 -Wl-b_BANK44=0x8000 -Wl-b_BANK45=0x8000 -Wl-b_BANK46=0x8000 -Wl-b_BANK47=0x8000 ^
-Wl-b_BANK48=0x8000 -Wl-b_BANK49=0x8000 -Wl-b_BANK50=0x8000 -Wl-b_BANK51=0x8000 -Wl-b_BANK52=0x8000 -Wl-b_BANK53=0x8000 -Wl-b_BANK54=0x8000 -Wl-b_BANK55=0x8000 ^
-Wl-b_BANK56=0x8000 -Wl-b_BANK57=0x8000 -Wl-b_BANK58=0x8000 -Wl-b_BANK59=0x8000 -Wl-b_BANK60=0x8000 -Wl-b_BANK61=0x8000 -Wl-b_BANK62=0x8000 -Wl-b_BANK63=0x8000 ^
../lib/SMSlib.lib ^
../lib/PSGlib.rel ^
banks/bank2.rel  banks/bank3.rel  banks/bank4.rel  banks/bank5.rel banks/bank6.rel  banks/bank7.rel  banks/bank8.rel  banks/bank9.rel ^
banks/bank10.rel banks/bank11.rel banks/bank12.rel banks/bank13.rel banks/bank14.rel banks/fixedbank.rel ^
banks/bank16.rel banks/bank17.rel banks/bank18.rel banks/bank19.rel banks/bank20.rel banks/bank21.rel banks/bank22.rel banks/bank23.rel ^
banks/bank24.rel banks/bank25.rel banks/bank26.rel banks/bank27.rel banks/bank28.rel banks/bank29.rel banks/bank30.rel banks/bank31.rel ^
banks/bank32.rel banks/bank33.rel banks/bank34.rel banks/bank35.rel banks/bank36.rel banks/bank37.rel banks/bank38.rel banks/bank39.rel ^
banks/bank40.rel banks/bank41.rel banks/bank42.rel banks/bank43.rel banks/bank44.rel banks/bank45.rel banks/bank46.rel banks/bank47.rel ^
banks/bank48.rel banks/bank49.rel banks/bank50.rel banks/bank51.rel banks/bank52.rel banks/bank53.rel banks/bank54.rel banks/bank55.rel ^
banks/bank56.rel banks/bank57.rel banks/bank58.rel banks/bank59.rel banks/bank60.rel banks/bank61.rel banks/bank62.rel banks/bank63.rel ^
devkit/_sms_manager.rel ^
devkit/_snd_manager.rel ^
engine/asm_manager.rel engine/audio_manager.rel engine/cartoon_manager.rel ^
engine/collision_manager.rel engine/command_manager.rel engine/content_manager.rel ^
engine/debug_manager.rel engine/enum_manager.rel engine/game_manager.rel engine/font_manager.rel  engine/global_manager.rel ^
engine/graphics_manager.rel engine/hack_manager.rel engine/input_manager.rel ^
engine/level_manager.rel engine/player_manager.rel engine/riff_manager.rel engine/sample_manager.rel ^
engine/screen_manager.rel engine/scroll_manager.rel engine/sprite_manager.rel ^
engine/storage_manager.rel engine/tile_manager.rel engine/timer_manager.rel engine/util_manager.rel ^
object/audio_object.rel object/command_object.rel object/game_object.rel object/hack_object.rel object/level_object.rel ^
object/player_object.rel object/riff_object.rel object/scroll_object.rel object/storage_object.rel object/timer_object.rel object/tile_object.rel ^
screen/beat_screen.rel screen/begin_screen.rel screen/boss_screen.rel screen/cont_screen.rel screen/dead_screen.rel ^
screen/demo_screen.rel screen/diff_screen.rel ^
screen/func_screen.rel screen/init_screen.rel screen/intro_screen.rel screen/load_screen.rel screen/level_screen.rel ^
screen/none_screen.rel screen/option_screen.rel screen/over_screen.rel screen/pass_screen.rel screen/play_screen.rel ^
screen/ready_screen.rel screen/record_screen.rel screen/repeat_screen.rel ^
screen/splash_screen.rel screen/start_screen.rel screen/test_screen.rel ^
screen/title_screen.rel

:: Execute
"C:/Program Files/SDCC/bin/ihx2sms.exe" output.ihx output.sms

:: Copy
copy output.sms ..\TestBuild.sms

:: Delete
cd banks
if exist "*.asm" del "*.asm" > nul; if exist "*.lst" del "*.lst" > nul; if exist "*.sym" del "*.sym" > nul
cd ..

cd devkit
if exist "*.asm" del "*.asm" > nul; if exist "*.lst" del "*.lst" > nul; if exist "*.sym" del "*.sym" > nul
cd ..

cd engine
if exist "*.asm" del "*.asm" > nul; if exist "*.lst" del "*.lst" > nul; if exist "*.sym" del "*.sym" > nul
cd ..

cd object
if exist "*.asm" del "*.asm" > nul; if exist "*.lst" del "*.lst" > nul; if exist "*.sym" del "*.sym" > nul
cd ..

cd screen
if exist "*.asm" del "*.asm" > nul; if exist "*.lst" del "*.lst" > nul; if exist "*.sym" del "*.sym" > nul
cd ..

if exist "*.asm" del "*.asm" > nul; if exist "*.ihx" del "*.ihx" > nul; if exist "*.lk"  del "*.lk"  > nul
if exist "*.lst" del "*.lst" > nul; if exist "*.sym" del "*.sym" > nul


:: Run
::java -jar C:/SEGA/Emulicious/Emulicious.jar output.sms
C:/SEGA/Fusion/Fusion.exe output.sms
