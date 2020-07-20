#ifndef _USABLE_FUNCTIONS_INTERNAL_H_
#define _USABLE_FUNCTIONS_INTERNAL_H_

#include "usable_functions.h"
#include "stdio.h"
#include "string.h"

#define HAS_VALUE 1

char * get_screen(char * incoming_string);
char * get_main_screen_info(char * incoming_string);
char * get_key_from_str(char * key);


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


