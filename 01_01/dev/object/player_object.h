#ifndef _PLAYER_OBJECT_H_
#define _PLAYER_OBJECT_H_

typedef struct tag_struct_player_object
{
	unsigned char initX;
	unsigned int posnX;
	unsigned int tileX;
	unsigned char lookX;
	unsigned char posnY;
	unsigned char tileY;
	unsigned int leapY;
	unsigned char drawX, drawY;
	unsigned char player_state;
	unsigned char jumper_index;
	unsigned char deltaY_index;
	unsigned char player_frame;
	unsigned char player_lives;
	unsigned char motion_count;

} struct_player_object;

// Player Manager.
extern const unsigned char player_object_starts[];
extern const unsigned char player_object_deltas[];

extern const unsigned char player_moving_deltaX[];
extern const unsigned char player_ground_deltaX[];
extern const unsigned char player_flying_deltaX[];

extern const unsigned char player_lives_headX[];

// Total screen jumps.
extern const signed int *jump_array_ptr[];
extern const unsigned char jump_array_len[];

// Title screen flips.
extern const unsigned char *flip_array_ptr[];

#endif//_PLAYER_OBJECT_H_