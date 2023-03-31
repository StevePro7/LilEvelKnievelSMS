#ifndef _RIFF_MANAGER_H_
#define _RIFF_MANAGER_H_

#include "../object/riff_object.h"

#define RIFF_START_DEAD		9
#define RIFF_START_PASS		17
#define RIFF_START_LOAD		20
#define RIFF_START_OVER		23
#define RIFF_START_TITLE	24
#define RIFF_START_SPLASH	25

void engine_riff_manager_init();
void engine_riff_manager_loop( unsigned char index );
void engine_riff_manager_play( unsigned char index );

#endif//_RIFF_MANAGER_H_
