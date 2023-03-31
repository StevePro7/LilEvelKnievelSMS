#ifndef _LEVEL_OBJECT_H_
#define _LEVEL_OBJECT_H_

#include "../engine/global_manager.h"

typedef struct tag_struct_level_object
{
	unsigned char *level_data;
	unsigned int level_size;
	unsigned char level_bank;
	unsigned int level_check;
	unsigned char check_width;
	unsigned char column_draw;

} struct_level_object;

extern unsigned char level_platforms[];

#endif//_LEVEL_OBJECT_H_