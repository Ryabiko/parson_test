#include "usable_functions_internal.h"


char * get_screen(char * incoming_string){
	JSON_Value * incoming_value = json_parse_string(incoming_string);
	JSON_Value * template = json_parse_string("{\"screen\":\"\"}");

	if (json_validate(template, incoming_value) == JSONSuccess)
	{
		return sys_info.current_screen;
	}
	else return NULL;
}

char * get_main_screen_info(char * incoming_string){ //аналогично для side_screen
	JSON_Value * incoming_value = json_parse_string(incoming_string);
	JSON_Value * screen_template = json_parse_string("{\"screen\":\"\"}");
	JSON_Value * number_lines_template = json_parse_string("{\"number_lines\":\"\"}");
	JSON_Value * cell_x_y_template = json_parse_string("{\"screen\":\"\"}");

	if (json_validate(screen_template, incoming_value) == JSONSuccess)
	{
		return sys_info.current_screen;
	}
	else if(json_validate(number_lines_template, incoming_value) == JSONSuccess){
		return NULL;
	}
	else if(json_validate(cell_x_y_template, incoming_value) == JSONSuccess){
		return NULL;	//известно ли тут изначально, сколько будет ячеек 
	}
	else return NULL;
}