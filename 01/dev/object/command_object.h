#ifndef _COMMAND_OBJECT_H_
#define _COMMAND_OBJECT_H_

typedef struct tag_struct_command_object
{
	unsigned int frame_index;
	unsigned char curr_command;
	unsigned char prev_command;

} struct_command_object;

extern unsigned int command_frame_index[];
extern unsigned char command_this_command[];

#endif//_COMMAND_OBJECT_H_