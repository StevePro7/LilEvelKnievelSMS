#include "input_manager.h"
#include "../devkit/_sms_manager.h"

#define INPUT_MOVEMENT		1

#ifdef _CONSOLE
#else
#pragma disable_warning 110
#pragma disable_warning 126
#endif

// Must be static to persist values!
static unsigned int curr_joypad1 = 0;
static unsigned int prev_joypad1 = 0;

static unsigned char( *hold_method )( unsigned char data );
static unsigned char( *move_method )( unsigned char data );

static unsigned char my_hold_method( unsigned char data );
static unsigned char my_move_method( unsigned char data );

// Public methods.
void engine_input_manager_init()
{
	if( INPUT_MOVEMENT )
	{
		hold_method = my_hold_method;
		move_method = my_move_method;
	}
	else
	{
		// Alternate.
		hold_method = my_move_method;
		move_method = my_hold_method;
	}
}
void engine_input_manager_update()
{
	prev_joypad1 = curr_joypad1;
	curr_joypad1 = devkit_SMS_getKeysStatus();
}

unsigned char engine_input_manager_hold( unsigned char data )
{
	return hold_method( data );
}

unsigned char engine_input_manager_move( unsigned char data )
{
	return move_method( data );
}

static unsigned char my_hold_method( unsigned char data )
{
	return curr_joypad1 & data && !( prev_joypad1 & data );
}

static unsigned char my_move_method( unsigned char data )
{
	return curr_joypad1 & data;
}