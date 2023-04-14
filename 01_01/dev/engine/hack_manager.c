#include "hack_manager.h"
#include "global_manager.h"
#include "enum_manager.h"
#include "game_manager.h"

// Global variable.
struct_hack_object global_hack_object;

#define PEEK( addr)			(* ( unsigned char *)( addr ) )
#define POKE( addr, data )	(* ( unsigned char *)( addr ) = ( data ) )

#define HACKER_START		0x0050

#ifdef _CONSOLE
#else
#pragma disable_warning 110
#pragma disable_warning 126
#endif

void engine_hack_manager_init()
{
	struct_hack_object *ho = &global_hack_object;

	ho->hack_delay = 0;
	ho->hack_isgod = 0;
	ho->hack_inair = 0;
	ho->hack_ultra = 0;
	ho->hack_music = 0;
	ho->hack_sound = 0;
	ho->hack_riffs = 0;
}

void engine_hack_manager_load()
{
	struct_hack_object *ho = &global_hack_object;
	struct_game_object *go = &global_game_object;

#ifndef _CONSOLE

	ho->hack_delay = PEEK( HACKER_START - 1 );			// 0x004F		// Used to speed through any game delay.
	ho->hack_isgod = PEEK( HACKER_START + 0 );			// 0x0050		// Non-zero value enables invincibility.
	ho->hack_inair = PEEK( HACKER_START + 1 );			// 0x0051		// Jump once while falling from gravity.
	ho->hack_ultra = PEEK( HACKER_START + 2 );			// 0x0052		// Tougher platform collision detection.
	ho->hack_music = PEEK( HACKER_START + 3 );			// 0x0053		// Set 0=Music to play otherwise silent.
	ho->hack_sound = PEEK( HACKER_START + 4 );			// 0x0054		// Set 0=Sound to play otherwise silent.
	ho->hack_riffs = PEEK( HACKER_START + 5 );			// 0x0055		// Set 0=Riffs to play otherwise silent.

#endif

	// Invert default values.
	ho->hack_inair = !ho->hack_inair;
	ho->hack_music = !ho->hack_music;
	ho->hack_sound = !ho->hack_sound;
	ho->hack_riffs = !ho->hack_riffs;

	// Tester values
	//ho->hack_delay = 0;
	//ho->hack_inair = 1;								// User can jump once while falling from gravity.
	//ho->hack_ultra = 0;								// User has more aggressive collision detections.

	ho->hack_music = 1;
	ho->hack_sound = 1;
	ho->hack_riffs = 1;
	// Tester values

	// Late setting: to fix this up!
	go->game_isgod = ho->hack_isgod;
}
