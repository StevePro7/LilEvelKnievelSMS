#ifndef _AUDIO_MANAGER_H_
#define _AUDIO_MANAGER_H_

#include "../object/audio_object.h"

// Global variable.
extern struct_audio_object global_audio_object;

void engine_audio_manager_init();
void engine_music_manager_play( unsigned char index );
void engine_music_manager_playnorepeat( unsigned char index );
void engine_music_manager_stop();
void engine_music_manager_resume();
void engine_sound_manager_play( unsigned char index );
void engine_sound_manager_stop();
void engine_audio_manager_update();

#endif//_AUDIO_MANAGER_H_