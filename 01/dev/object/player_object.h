#ifndef _PLAYER_OBJECT_H_
#define _PLAYER_OBJECT_H_

typedef struct tag_struct_player_object
{
	unsigned char initX;
	unsigned int posnX;			// max posnX	2,047	i.e. 2048-1
	unsigned int tileX;			// 255 * 8		2,047??
	//unsigned char tileX;			// 255 * 8		2,047??
	unsigned char lookX;
	unsigned char posnY;
	unsigned char tileY;
	unsigned int leapY;
	unsigned char drawX, drawY;
	unsigned char player_state;
	//unsigned char player_index;
	unsigned char jumper_index;
	unsigned char deltaY_index;
	//unsigned char jumper_array;		// replaced by jump_ptr	TODO delete
	unsigned char player_frame;
	unsigned char player_lives;
	unsigned char motion_count;

} struct_player_object;

// TODO re-instate in fixed bank
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

//TODO delete this block - don't need to be public??
//extern const signed int jump_array_00[];
//extern const signed int jump_array_01[];
//extern const signed int jump_array_02[];
//extern const signed int jump_array_03[];
//extern const signed int jump_array_04[];

//TODO delete
//extern const signed int jump_array_99[];
//extern const signed int jump_array_20[];
//extern const signed int jump_array_40[];
//extern const signed int jump_array_80[];
//extern const signed int jump_array_130[];



#endif//_PLAYER_OBJECT_H_