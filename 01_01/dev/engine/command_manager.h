#ifndef _COMMAND_MANAGER_H_
#define _COMMAND_MANAGER_H_

#include "../object/command_object.h"

// Global variable.
extern struct_command_object global_command_object;

void engine_command_manager_init();
void engine_command_manager_load( unsigned int *storage_frame_index, unsigned char* storage_this_command );
unsigned char engine_command_manager_build( unsigned char state, unsigned char input1, unsigned char input2, unsigned char input3, unsigned char input4, unsigned char input5, unsigned char input6 );
void engine_command_manager_record( unsigned int frame, unsigned char command );
void engine_command_manager_update( unsigned char command );

#endif//_COMMAND_MANAGER_H_