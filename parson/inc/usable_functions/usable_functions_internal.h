#ifndef _USABLE_FUNCTIONS_INTERNAL_H_
#define _USABLE_FUNCTIONS_INTERNAL_H_

#include "usable_functions.h"

char * get_screen(char * incoming_string);

struct _sys_info{
	char * current_screen;

} sys_info;


struct _screen_info{
	int lines_quantity;
	int * cell_1_2;
};

struct _screen_info main_screen;
struct _screen_info side_screen;

#endif//_USABLE_FUNCTIONS_INTERNAL_H_


