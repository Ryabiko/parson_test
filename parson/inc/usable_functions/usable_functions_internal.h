#ifndef _USABLE_FUNCTIONS_INTERNAL_H_
#define _USABLE_FUNCTIONS_INTERNAL_H_

#include "usable_functions.h"

char * get_screen(char * incoming_string);

struct _sys_info{
	char * current_screen;

} sys_info;


struct screen_info{
	int number_lines;
	int * cell_1_2;
};
#endif//_USABLE_FUNCTIONS_INTERNAL_H_


