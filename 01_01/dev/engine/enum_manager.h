#ifndef _ENUM_MANAGER_H_
#define _ENUM_MANAGER_H_

typedef enum tag_enum_screen_type
{
	screen_type_none = 0,
	screen_type_splash = 1,
	screen_type_begin = 2,
	screen_type_intro = 3,
	screen_type_title = 4,
	screen_type_demo = 5,
	screen_type_diff = 6,
	screen_type_level = 7,
	screen_type_start = 8,
	screen_type_init = 9,
	screen_type_load = 10,
	screen_type_ready = 11,
	screen_type_play = 12,
	screen_type_pass = 13,
	screen_type_dead = 14,
	screen_type_cont = 15,
	screen_type_over = 16,
	screen_type_boss = 17,
	screen_type_beat = 18,
	screen_type_option = 19,
	screen_type_record = 20,
	screen_type_repeat = 21,
	screen_type_test = 22,
	screen_type_func = 23,

} enum_screen_type;

typedef enum tag_enum_input_type
{
	input_type_up = 0x01,
	input_type_down = 0x02,
	input_type_left = 0x04,
	input_type_right = 0x08,
	input_type_fire1 = 0x10,
	input_type_fire2 = 0x20,

} enum_input_type;

typedef enum tag_enum_player_state
{
	player_state_isonground = 0,
	player_state_isintheair = 1,
	player_state_isnowdying = 2,
	//player_state_completion = 2,
	player_state_iskilldead = 3,

} enum_player_state;

// TODO - replace these enums for swap / flip.
typedef enum tag_enum_player_frame
{
	player_frame_ground_rght_01 = 0,
	player_frame_ground_rght_02 = 1,
	player_frame_ground_left_01 = 2,
	player_frame_ground_left_02 = 3,
	player_frame_theair_rght_01 = 4,
	player_frame_theair_rght_02 = 5,
	player_frame_theair_rght_03 = 6,
	player_frame_theair_rght_04 = 7,
	player_frame_theair_left_01 = 8,
	player_frame_theair_left_02 = 9,
	player_frame_theair_left_03 = 10,
	player_frame_theair_left_04 = 11,
	player_frame_sprite_maximum = 12,

} enum_player_frame;

typedef enum tag_enum_scroll_state
{
	scroll_state_none = 0,
	scroll_state_tile = 1,
	scroll_state_line = 2,
	scroll_state_comp = 3,

} enum_scroll_state;

typedef enum tag_enum_difficulty_type
{
	difficulty_type_easier = 0,
	difficulty_type_normal = 1,
	difficulty_type_harder = 2,
	difficulty_type_insane = 3,

} enum_difficulty_type;

typedef enum tag_enum_jump_type
{
	jump_type_fall = 0,
	jump_type_skip = 1,
	jump_type_jump = 2,
	jump_type_leap = 3,
	jump_type_hurl = 4,

} enum_jump_type;

typedef enum tag_enum_stage_mode
{
	stage_mode_inc0 = 0,
	stage_mode_inc1 = 1,
	stage_mode_inc2 = 2,
	stage_mode_inc3 = 3,
	stage_mode_inc4 = 4,

} enum_enum_stage_mode;

typedef enum tag_enum_switch_mode
{
	switch_mode_no = 0,
	switch_mode_yes = 1,

} enum_switch_mode;

typedef enum tag_enum_music_type
{
	music_type_tune0 = 0,
	music_type_tune1 = 1,
	music_type_tune2 = 2,
	music_type_tune3 = 3,
	music_type_conts = 4,
	music_type_overs = 5,
	music_type_beats = 6,

} enum_enum_music_type;

typedef enum tag_enum_tile_type
{
	tile_type_waves_block = 0,
	tile_type_bridge_midd = 1,
	tile_type_bridge_side = 2,
	tile_type_bridge_sign = 3,
	tile_type_island_midd = 4,
	tile_type_island_left = 5,
	tile_type_island_rght = 6,
	tile_type_island_sign = 7,
	tile_type_islandTreeL = 8,
	tile_type_islandTreeR = 9,
	tile_type_turtle_sea1 = 10,
	tile_type_turtle_sea2 = 11,
	tile_type_turtle_fly1 = 12,
	tile_type_turtle_fly2 = 13,
	tile_type_turtle_fly3 = 14,
	tile_type_turtle_fly4 = 15,

	tile_type_bridge_side_flip = 16,
	tile_type_bridge_sign_goal = 17,
	tile_type_island_sign_goal = 18,

} enum_tile_type;

typedef enum tag_enum_sprite_mode
{
	sprite_mode_normai = 1,
	sprite_mode_zoomed = 2,

} enum_sprite_mode_type;

typedef enum tag_enum_cloud_type
{
	cloud_type_large = 0,
	cloud_type_small = 1,

} enum_cloud_type;

#endif//_ENUM_MANAGER_H_