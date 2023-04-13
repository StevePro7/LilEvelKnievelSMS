#ifndef _STORAGE_OBJECT_H_
#define _STORAGE_OBJECT_H_

#include "../engine/global_manager.h"

// Reference: http://www.smspower.org/forums/16013-DevkitSMSSMSlibMissingRequestingFeatures#91899
typedef struct tag_struct_storage_object
{
	unsigned long Magic;

	unsigned char storage_difficulty;
	unsigned char storage_world;
	unsigned char storage_round;
	unsigned char storage_level;
	unsigned char storage_point;
	unsigned char storage_saved;
	unsigned char storage_padding[ STORAGE_BUFFER ];

	unsigned int storage_frame_index[ MAX_COMMANDS ];
	unsigned char storage_this_command[ MAX_COMMANDS ];
	unsigned char terminal;

} struct_storage_object;

#endif//_STORAGE_OBJECT_H_