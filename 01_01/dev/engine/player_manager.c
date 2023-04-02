#include "player_manager.h"
#include "cartoon_manager.h"
#include "collision_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "sprite_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"
#include "../banks/bank2.h"
#include <stdlib.h>

#define PLAYER_MIN_HIGH		32
#define PLAYER_MAX_HIGH		168
#define MOTION_ANIMATES		25
#define DOUBLE_ANIMATES		75
#define PLAYER_HEAD_ROW		172
#define UFIX(x)				((unsigned char)((x)>>8))

#ifdef _CONSOLE
#else
#pragma disable_warning 110
#pragma disable_warning 261
#endif

// Global variable.
struct_player_object global_player_object;

static void updatePlayer();
static void updatePlayerX();
static void updatePlayerY();
static unsigned char updatePlayerFrameGroundToFlying( unsigned char player_frame );
static unsigned char updatePlayerFrameFlyingToGround( unsigned char player_frame );

static const signed int *jump_ptr;
static unsigned char jump_len;
static unsigned char moving_deltaX, ground_deltaX, flying_deltaX;

void engine_player_manager_init()
{
	struct_player_object *po = &global_player_object;
	po->initX = 0; po->posnX = 0; po->tileX = 0; po->lookX = 0;
	po->posnY = 0; po->tileY = 0; po->leapY = 0;
	po->drawX = 0; po->drawY = 0;
	po->player_state = player_state_isonground;
	po->jumper_index = 0; po->deltaY_index = 0;
	po->player_frame = player_frame_ground_rght_01;
	//po->player_lives = MAX_LIVES;
	po->motion_count = 0;
	jump_ptr = NULL;
	jump_len = 0;
	updatePlayer();
	moving_deltaX = 2;
	ground_deltaX = 1;
	flying_deltaX = 1;
}

// todo - need to re-init player_lives to 3x every game "load"
// todo - if difficulty == easier || normal then lives += 1 ?

void engine_player_manager_initX( unsigned char difficulty, unsigned char world )
{
	struct_player_object *po = &global_player_object;
	po->initX = player_object_starts[ difficulty ];
	po->posnX = po->initX;
	po->drawX = po->posnX - 16;
	updatePlayerX();

	// Update player deltaX values pending world.
	moving_deltaX = player_moving_deltaX[ world ];
	ground_deltaX = player_ground_deltaX[ world ];
	flying_deltaX = player_flying_deltaX[ world ];
}

// TODO - need algorithm to align which individual screen to a checkpoint
void engine_player_manager_loadX( unsigned char checkScreen )
{
	struct_player_object *po = &global_player_object;
	unsigned int offset;
	//unsigned char screen;

	//screen = checkPoint;
	//offset = screen * PIXELS_WIDE;
	offset = checkScreen * PIXELS_WIDE;
	po->posnX = po->initX + offset;
	updatePlayerX();
}

void engine_player_manager_loadY( unsigned char player_loadY )
{
	struct_player_object *po = &global_player_object;
	po->player_state = player_state_isonground;

	// Check for starting point without platform.
	if( 0 == player_loadY )
	{
		po->player_state = player_state_isintheair;
		po->posnY = PLAYER_MIN_HIGH;
		po->jumper_index = 0;
		po->deltaY_index = 0;
		po->player_frame = player_frame_theair_rght_01;
		//po->player_frame = updatePlayerFrameGroundToFlying( po->player_frame );

		// Set the jump array information.
		jump_ptr = jump_array_ptr[ po->jumper_index ];
		jump_len = jump_array_len[ po->jumper_index ];
	}
	else
	{
		po->posnY = player_loadY << 3;
		po->player_frame = player_frame_ground_rght_01;
		//po->player_frame = updatePlayerFrameFlyingToGround( po->player_frame );
	}

	po->leapY = po->posnY << 8;
	updatePlayerY();
}

void engine_player_manager_lives( unsigned char difficulty )
{
	struct_player_object *po = &global_player_object;
	po->player_lives = MAX_LIVES;

	// TODO Do I want to implement this?	Don't think I'll bother with this
	if( difficulty_type_easier == difficulty || difficulty_type_normal == difficulty )
	{
		po->player_lives += 1;
		//po->player_lives += 0;
	}
}

unsigned char engine_player_manager_get_deltaX( unsigned char state, unsigned char command )
{
	struct_player_object *po = &global_player_object;
	unsigned char deltaX;

	//deltaX = 0;
	//deltaX = 2;		// TODO - try 2, 4, 6, 8
	deltaX = moving_deltaX;
	//deltaX = 6;		// TODO delete
	if( ( COMMAND_LEFT_MASK & command ) == COMMAND_LEFT_MASK )
	{
		// Back up when facing forward and going slower...
		if( po->player_frame < player_frame_ground_left_01 )
		{
			// TODO - revert back this line...
			//po->player_frame = player_frame_theair_rght_01;
			//po->player_frame = player_frame_ground_rght_01;
		}

		//deltaX -= 2;
		deltaX -= ground_deltaX;
	}
	if( ( COMMAND_RGHT_MASK & command ) == COMMAND_RGHT_MASK )
	{
		//deltaX += 2;
		deltaX += ground_deltaX;
	}

	// Add 1px when player in the air.
	if( player_state_isintheair == state )
	{
		// IMPORTANT - harder w/ onground=2px and inair delta+=1 will fall over single gap but deltaX+=2 will "survive"
		//deltaX += 2;		// post 1st March 2023
		//deltaX += 1;		// PRE 1st March 2023
		deltaX += flying_deltaX;

		// TODO delete = testing
		//deltaX = 4;
		// TODO delete = testing
	}

	// TODO IMPORTANT - hardcoded for jump array testing!!
	//deltaX = 5;
	return deltaX;
}

//TODO delete out-by-one version
//signed int engine_player_manager_get_deltaY()
//{
//	// IMPORTANT this function will only be invoked when player is in the air.
//	struct_player_object *po = &global_player_object;
//	signed int deltaY = 0;
//
//	if( NULL != jump_ptr )
//	{
//		deltaY = jump_ptr[ po->deltaY_index ];
//		if( po->deltaY_index < jump_len - 1 )
//		{
//			po->deltaY_index++;
//		}
//	}
//
//	return deltaY;
//}

signed int engine_player_manager_get_deltaY()
{
	// IMPORTANT this function will only be invoked when player is in the air.
	struct_player_object *po = &global_player_object;
	signed int deltaY = 0;

	if( NULL != jump_ptr )
	{
		deltaY = jump_ptr[ po->deltaY_index ];
		po->deltaY_index++;

		if( po->deltaY_index >= jump_len - 1 )
		{
			po->deltaY_index = jump_len - 1;
		}
	}

	return deltaY;
}

void engine_player_manager_set_action( unsigned char frame, unsigned char command )
{
	struct_player_object *po = &global_player_object;
	unsigned char newFrame;
	unsigned char newIndex;

	// Player on ground.
	newFrame = po->player_frame;
	if( ( COMMAND_JUMP_MASK & command ) == COMMAND_JUMP_MASK )
	{
		// new logic
		po->player_state = player_state_isintheair;

		// TODO - calculate this - determine jump index
		if( ( COMMAND_HIGH_MASK & command ) == COMMAND_HIGH_MASK )
		{
			//newIndex = jump_type_hurl;	// newIndex = 4;
			//newIndex = jump_type_jump;	// newIndex = 2;
			newIndex = jump_type_leap;	// newIndex = 3;
			if( ( COMMAND_LEFT_MASK & command ) == COMMAND_LEFT_MASK )
			{
				//newIndex = jump_type_leap;	// newIndex = 3;
				newIndex = jump_type_jump;	// newIndex = 2;
			}
			if( ( COMMAND_RGHT_MASK & command ) == COMMAND_RGHT_MASK )
			{
				newIndex = jump_type_hurl;	// newIndex = 4;
			}
		}
		else
		{
			//newIndex = jump_type_jump;	// newIndex = 2;
			//newIndex = jump_type_leap;	// newIndex = 3;
			newIndex = jump_type_jump;	// newIndex = 2;
			if( ( COMMAND_LEFT_MASK & command ) == COMMAND_LEFT_MASK )
			{
				newIndex = jump_type_skip;	// newIndex = 1;
			}
			if( ( COMMAND_RGHT_MASK & command ) == COMMAND_RGHT_MASK )
			{
				//newIndex = jump_type_jump;	// newIndex = 2;
				newIndex = jump_type_leap;	// newIndex = 3;
			}
		}
		// TODO - calculate this - determine jump index
		//newIndex = 2;
		////newIndex = 6;		// TODO - delete - hard code this value during physics testing!!
		//if( ( COMMAND_LEFT_MASK & command ) == COMMAND_LEFT_MASK )
		//{
		//	newIndex = 1;
		//}
		//if( ( COMMAND_RGHT_MASK & command ) == COMMAND_RGHT_MASK )
		//{
		//	newIndex = 3;
		//}

		newFrame = updatePlayerFrameGroundToFlying( po->player_frame );
		//po->player_frame = updatePlayerFrameGroundToFlying( po->player_frame );

		// TODO test this
		//if( ( COMMAND_HIGH_MASK & command ) == COMMAND_HIGH_MASK )
		//{
		//	newIndex += 1;
		//	//po->jumper_index += 1;
		//}

		// TODO delete = testing
		po->jumper_index = newIndex;
		//po->jumper_index = 4;	// TODO delete = testing
		// TODO delete = testing
		po->deltaY_index = 0;

		// Set the jump array information.
		jump_ptr = jump_array_ptr[ po->jumper_index ];
		jump_len = jump_array_len[ po->jumper_index ];

		// TODO delete this debugging info - for newIndex!!
		//engine_font_manager_data( po->jumper_index, 31, 5 );
		// TODO delete this debugging info - for newIndex!!


		// old logic
		//po->player_state = player_state_isintheair;

		//// TODO - calculate this - determine jump index
		//newIndex = 2;
		////newIndex = 6;		// TODO - delete - hard code this value during physics testing!!
		//if( ( COMMAND_LEFT_MASK & command ) == COMMAND_LEFT_MASK )
		//{
		//	newIndex = 1;
		//}
		//if( ( COMMAND_RGHT_MASK & command ) == COMMAND_RGHT_MASK )
		//{
		//	newIndex = 3;
		//}

		//newFrame = updatePlayerFrameGroundToFlying( po->player_frame );
		////po->player_frame = updatePlayerFrameGroundToFlying( po->player_frame );

		//// TODO test this
		//if( ( COMMAND_HIGH_MASK & command ) == COMMAND_HIGH_MASK )
		//{
		//	newIndex += 1;
		//	//po->jumper_index += 1;
		//}

		//// TODO delete = testing
		//po->jumper_index = newIndex;
		////po->jumper_index = 4;	// TODO delete = testing
		//// TODO delete = testing
		//po->deltaY_index = 0;

		//// Set the jump array information.
		//jump_ptr = jump_array_ptr[ po->jumper_index ];
		//jump_len = jump_array_len[ po->jumper_index ];

		//// TODO delete this debugging info - for newIndex!!
		//engine_font_manager_data( po->jumper_index, 31, 5 );
		//// TODO delete this debugging info - for newIndex!!
	}
	else
	{
		// Player in the air.
		if( ( COMMAND_SWAP_MASK & command ) == COMMAND_SWAP_MASK )
		{
			//po->player_frame = engine_cartoon_manager_swap( frame );
			newFrame = engine_cartoon_manager_swap( frame );
			po->player_frame = newFrame;
		}
		if( ( COMMAND_FLIP_MASK & command ) == COMMAND_FLIP_MASK )
		{
			//newFrame = po->player_frame;
			newFrame = engine_cartoon_manager_flip( frame, command );
			po->player_frame = newFrame;

			//engine_font_manager_data( newFrame, 30, 11 );
			//engine_font_manager_data( po->player_frame, 30, 13 );
			//po->player_frame = engine_cartoon_manager_flip( frame, command );
			//engine_font_manager_data( po->player_frame, 30, 14 );
		}
	}

	po->player_frame = newFrame;
}

void engine_player_manager_horz( unsigned char deltaX )
{
	struct_player_object *po = &global_player_object;
	po->posnX += deltaX;
	updatePlayerX();
}
void engine_player_manager_vert( signed int deltaY )
{
	struct_player_object *po = &global_player_object;
	po->leapY += deltaY;
	po->posnY = UFIX( po->leapY );
	updatePlayerY();
}

void engine_player_manager_bounds( signed int deltaY, unsigned char posnY, unsigned char invincible )
{
	struct_player_object *po = &global_player_object;
	if( deltaY > 0 )
	{
		if( posnY >= PLAYER_MAX_HIGH && invincible )
		{
			// Cannot fall through the screen.
			po->player_state = player_state_isonground;
			po->posnY = PLAYER_MAX_HIGH;
			po->leapY = po->posnY << 8;
			po->jumper_index = 0;
			po->deltaY_index = 0;
			po->player_frame = updatePlayerFrameFlyingToGround( po->player_frame );
			updatePlayerY();
		}
	}
	else if( deltaY < 0 )
	{
		// Cannot jump through the screen.
		if( posnY < PLAYER_MIN_HIGH )
		{
			po->posnY = PLAYER_MIN_HIGH;
			po->leapY = po->posnY << 8;
			updatePlayerY();
		}
	}
}

enum_player_state engine_player_manager_collision( unsigned char state, unsigned char lookX, unsigned char tileY, signed int deltaY, unsigned char posnY, unsigned char invincible )
{
	struct_player_object *po = &global_player_object;
	enum_player_state player_state;
	signed char collision;
	player_state = state;

	// Check if player fallen through to the water.
	if( posnY >= PLAYER_MAX_HIGH )
	{
		//// TODO check to see if only this code is necessary as the player_state will be isOnGround and all other player properties set from the bounds check earlier in the frame...
		//if( !invincible )
		//{
		//	// Otherwise update player dying state.
		//	player_state = player_state_isnowdying;
		//}
		// If God mode then simply revert back to "ground".
		if( invincible )
		{
			player_state = player_state_isonground;
			po->posnY = PLAYER_MAX_HIGH;
			po->leapY = po->posnY << 8;
			po->jumper_index = 0;
			po->deltaY_index = 0;
			updatePlayerY();
		}
		else
		{
			// Otherwise update player dying state.
			player_state = player_state_isnowdying;
		}
	}
	else
	{
		// Default check platform collision as before.
		collision = engine_collision_manager_player( lookX, tileY );
		if( player_state_isonground == player_state )
		{
			// Player was on the ground but now "falling" in the air due to gravity.
			if( INVALID_INDEX == collision )
			{
				player_state = player_state_isintheair;
				po->jumper_index = 0;
				po->deltaY_index = 0;
				po->player_frame = updatePlayerFrameGroundToFlying( po->player_frame );

				// Set the jump array information.
				jump_ptr = jump_array_ptr[ po->jumper_index ];
				jump_len = jump_array_len[ po->jumper_index ];
			}
		}
		else if( player_state_isintheair == player_state )
		{
			// Player in air descending thus check there could be platform to land on.
			if( deltaY > 0 )
			{
				// Only check collision with potential platform if "landing" stance OR player is invincible.
				if( player_frame_theair_rght_01 == po->player_frame || player_frame_theair_left_01 == po->player_frame || invincible )
				{
					if( INVALID_INDEX != collision )
					{
						player_state = player_state_isonground;
						po->jumper_index = 0;
						po->deltaY_index = 0;
						po->player_frame = updatePlayerFrameFlyingToGround( po->player_frame );

						// Ensure player aligns with platform landed on...
						po->posnY = tileY << 3;
						po->leapY = po->posnY << 8;
						updatePlayerY();
					}
				}
			}
		}
	}

	po->player_state = player_state;
	return player_state;
}

// IMPORTANT this function will only be invoked when player is on the ground.
void engine_player_manager_animate( unsigned char frame )
{
	struct_player_object *po = &global_player_object;
	if( frame < player_frame_theair_rght_01 )
	{
		po->motion_count++;
		//if( po->motion_count > DOUBLE_ANIMATES )		// TODO - overload function for cont_screen
		if( po->motion_count > MOTION_ANIMATES )
		{
			po->motion_count = 0;
			po->player_frame = engine_cartoon_manager_wave( frame );
		}
	}
}

void engine_player_manager_dying()
{
	struct_player_object *po = &global_player_object;
	po->posnX = po->initX;
	po->player_lives--;
}

unsigned char engine_player_manager_finish()
{
	struct_player_object *po = &global_player_object;
	unsigned char player_begY, player_endY;
	engine_collision_manager_finish( po->lookX, po->tileY, po->posnY, &player_begY, &player_endY );

	// Update co-ordinates.
	po->posnX = po->initX;
	po->posnY = player_begY;
	po->leapY = po->posnY << 8;
	updatePlayerY();

	// Update animation.
	if( po->player_frame < player_frame_ground_left_01 || ( po->player_frame > player_frame_theair_rght_01 && po->player_frame < player_frame_theair_left_01 ) )
	{
		po->player_frame = player_frame_theair_rght_01;
	}
	else if( po->player_frame < player_frame_theair_rght_01 || po->player_frame > player_frame_theair_left_01 )
	{
		po->player_frame = player_frame_theair_left_01;
	}

	// Get ready for gravity...
	po->jumper_index = 0;
	po->deltaY_index = 0;

	// Set the jump array information.
	jump_ptr = jump_array_ptr[ po->jumper_index ];
	jump_len = jump_array_len[ po->jumper_index ];

	return player_endY;
}

static void updatePlayer()
{
	updatePlayerX();
	updatePlayerY();
}
static void updatePlayerX()
{
	// https://johnysswlab.com/make-your-programs-run-faster-avoid-expensive-instructions
	struct_player_object *po = &global_player_object;
	po->tileX = po->posnX >> 3;
	po->lookX = po->tileX  & SCREEN_LESS_ONE;
}
static void updatePlayerY()
{
	struct_player_object *po = &global_player_object;
	po->drawY = po->posnY - 32;
	po->tileY = po->posnY >> 3;
	//po->leapY = po->posnY << 8;
}
static unsigned char updatePlayerFrameGroundToFlying( unsigned char player_frame )
{
	if( player_frame_ground_left_01 == player_frame || player_frame_ground_left_02 == player_frame )
	{
		return player_frame_theair_left_01;
	}

	return player_frame_theair_rght_01;
}
static unsigned char updatePlayerFrameFlyingToGround( unsigned char player_frame )
{
	// Swap back to appropriate player frame on ground.
	if( player_frame >= player_frame_theair_left_01 )
	{
		return player_frame_ground_left_01;
	}

	return player_frame_ground_rght_01;
}

void engine_player_manager_pass( unsigned char player_passX, unsigned char player_endY )
{
	struct_player_object *po = &global_player_object;
	signed int deltaY;

	po->posnX += player_passX;
	if( po->posnX >= LEVELS_SIDE )
	{
		po->posnX = LEVELS_SIDE;
	}

	po->drawX = po->posnX - 16;
	if( po->posnY != player_endY )
	{
		deltaY = engine_player_manager_get_deltaY();
		deltaY >>= 1;
		engine_player_manager_vert( deltaY );
	}

	if( po->posnY >= player_endY )
	{
		po->posnY = player_endY;
		updatePlayerY();
	}
}

void engine_player_manager_pass_frame()
{
	struct_player_object *po = &global_player_object;
	po->player_frame = ( player_frame_theair_rght_01 != po->player_frame ) ? player_frame_ground_left_02 : player_frame_ground_rght_02;
}

void engine_player_manager_dead( unsigned char player_deadX )
{
	struct_player_object *po = &global_player_object;
	signed int deltaY;

	po->posnX += player_deadX;
	if( po->posnX >= LEVELS_SIDE )
	{
		po->posnX = LEVELS_SIDE;
	}

	po->drawX = po->posnX - 16;
	if( po->posnY != PLAYER_DEAD )
	{
		deltaY = engine_player_manager_get_deltaY();
		deltaY >>= 1;
		
		engine_player_manager_vert( deltaY );
	}

	if( po->posnY >= PLAYER_DEAD )
	{
		po->posnY = PLAYER_DEAD;
		updatePlayerY();
	}
}

// TODO delete this as replaced by engine_player_manager_animate()
void engine_player_manager_count()
{
	//struct_player_object *po = &global_player_object;
	//po->motion_count++;
	//if( po->motion_count > MOTION_ANIMATES )
	//{
	//	// TODO calculate frame inverse when moving left!!
	//	po->motion_count = 0;
	//	po->player_frame = 1 - po->player_frame;
	//}
}
// TODO delete
void engine_player_manager_right( unsigned char deltaX )
{
	deltaX += 0;
	//	struct_player_object *po = &global_player_object;
	//	po->posnX += deltaX;
	//	updatePlayerX();
}
void engine_player_manager_down( signed char deltaY )
{
	deltaY += 0;
	//	struct_player_object *po = &global_player_object;
	//	po->posnY += deltaY;
	//	updatePlayerY();
}


void engine_player_manager_draw()
{
	struct_player_object *po = &global_player_object;
	unsigned char deltaDraw = player_object_deltas[ po->player_frame ];
	//unsigned char deltaDraw = 0;
	//if( 5 == po->player_frame || 7 == po->player_frame || 9 == po->player_frame || 11 == po->player_frame )
	//{
		//deltaDraw = 4;
	//}
	engine_sprite_manager_draw( po->player_frame, po->drawX + deltaDraw, po->drawY + deltaDraw );
}

void engine_player_manager_head()
{
	struct_player_object *po = &global_player_object;
	unsigned char index;
	for( index = 0; index < po->player_lives - 1; index++ )
	{
		engine_sprite_manager_head( player_lives_headX[ index ], PLAYER_HEAD_ROW );
	}
}