#ifndef _STORAGE_MANAGER_H_
#define _STORAGE_MANAGER_H_

#include "../object/storage_object.h"

// Global variable.
extern struct_storage_object global_storage_object;

unsigned char engine_storage_manager_available();
void engine_storage_manager_load();
void engine_storage_manager_save();
void engine_storage_manager_kill();

#endif//_STORAGE_MANAGER_H_