# Lil Evel Knievel SMS
Lil Evel Knievel game for the SMS Power! 2023 Competition.

![LilEvelKnievel](https://github.com/StevePro7/LilEvelKnievelSMS/blob/main/01_01/img/LilEvelKnievelSMS.png)

###### RELEASE
Monday, 27th March 2023

###### INTRO
A tribute to the greatest daredevil!
<br />
Lil Evel Knievel defies gravity with his gnarly skate board skills to conquer the original Wonderboy aquazone.

###### TOOLS
- Programming:	devkitSMS
- Compiler:		sdcc 4.1.0
- Languages:	C / Z80
- Visual Studio 2015
- Graphics:		BMP2Tile 0.43 / GIMP2 / paint.net
- Music:		pcmenc / VGM2PSG
- Assembler:	WLA-DX
- Emulators:	Emulicious / Fusion / Meka
- Debuggers:	VS Code Emulicious Debugger

###### SOURCE CODE
https://github.com/SteveProXNA/LilEvelKnievelSMS

###### ROM HACKING
You can hack this ROM!  
Download and dump LilEvelKnievel.sms into Hex Editor, e.g. HxD, and modify the bytes:
- 0x004F	Delay			Used to speed through any game delay.
- 0x0050	Invincible		Non-zero value enables invincibility.
- 0x0051	GravityJump		Jump once while falling from gravity.
- 0x0052	HarderLands		Tougher platform collision detection.
- 0x0053	Music Off		Set 0=Music to play otherwise silent.
- 0x0054	Sound Off		Set 0=Sound to play otherwise silent.
- 0x0055	Riffs Off		Set 0=Riffs to play otherwise silent.

###### LEVELS
Due to time constraints the initial V1.0 build ships with 10x levels only, unfortunately.  World:05 x Round:02.
<br />
But there are plans immediately to add more levels!  Pls let me know if you would like to contribute ideas...!

###### RIFFS
Things you may have missed; riffs from: AC/DC, Austin Powers, Gn'R, Simpsons, Van Halen, Wayne's World, WWF Wrestling

###### CREDITS
Extra special thanks to: sverx for [devkitSMS](https://github.com/sverx/devkitSMS) and Calindro for their 24/7 Tech Support!
<br />
Plus thanks goes to: Maxim, bock, eruiz00, haroldoop + kusfo

###### DOCUMENTATION
Links to documentation on games written for the Sega Master System using devkitSMS:
http://steveproxna.blogspot.com/search/label/devkitSMS

###### CONTACT
- Blog:http://steveproxna.blogspot.com
- Email:steven_boland@hotmail.com
- Twitter:[@SteveProXNA](http://twitter.com/SteveProXNA)