#ifndef _HACK_MANAGER_H_
#define _HACK_MANAGER_H_

#include "../object/hack_object.h"

// Global variable.
extern struct_hack_object global_hack_object;

void engine_hack_manager_init();
void engine_hack_manager_load();

#endif//_HACK_MANAGER_H_