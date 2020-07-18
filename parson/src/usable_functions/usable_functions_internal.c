#include "usable_functions_internal.h"


char * get_screen(char * incoming_string){
	JSON_Value * incoming_value = json_parse_string(incoming_string);
	JSON_Value * template = json_parse_string("{\"screen\":\"\"}");

	// JSON_Value *return_value = json_value_init_object();
 //    JSON_Object *return_object = json_value_get_object(return_value);

	if (json_validate(template, incoming_value) == JSONSuccess)
	{
		JSON_Object * incoming_object = json_value_get_object(incoming_value);
		json_object_set_string(incoming_object, "screen", sys_info.current_screen);

		return json_serialize_to_string(incoming_value);
		// return sys_info.current_screen;
	}
	else return NULL;
}

char * get_main_screen_info(char * incoming_string){ //аналогично для side_screen
	JSON_Value * incoming_value = json_parse_string(incoming_string);

	JSON_Value * lines_quantity_template = json_parse_string("{\"number_lines\":\"\"}");
	JSON_Value * cell_x_y_template = json_parse_string("{\"screen\":\"\"}");

	if(json_validate(lines_quantity_template, incoming_value) == JSONSuccess){
		JSON_Object * incoming_object = json_value_get_object(incoming_value);
		json_object_set_number(incoming_object, "lines_quantity", main_screen.lines_quantity);

		return json_serialize_to_string(incoming_value);
	}
	else if(json_validate(cell_x_y_template, incoming_value) == JSONSuccess){
		return NULL;	//известно ли тут изначально, сколько будет ячеек 
	}
	else return NULL;
}