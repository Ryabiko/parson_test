#include "usable_functions_internal.h"

char * free_symbols (char * source) {
	char * delimeters = "\"{:";

	int del_quantity = strspn(source, delimeters);

    return source + del_quantity;
}


char * get_key_from_str(char * key){
	char * suitable_symbols = "abcdefghijklmnopqrstuvwxyz_1234567890";


	char *	middle_string = free_symbols(key);
	int sym_quantity = strspn(middle_string, suitable_symbols);
	char	returning_string[sym_quantity];

	printf("\nsym_quantity:%d\n", sym_quantity);

	strncpy (returning_string, middle_string, sym_quantity);
	printf("\nreturning_string:%s\n", returning_string);

	char * returning_ptr = NULL;
	// strcpy(returning_ptr, returning_string);

    return returning_ptr;
    // return returning_string;
}


char * get_screen(char * incoming_string){
	JSON_Value * incoming_value = json_parse_string(incoming_string);
	JSON_Object * incoming_object = json_value_get_object(incoming_value);

	if (json_object_has_value(incoming_object, "screen") == HAS_VALUE)
	{
		json_object_set_string(incoming_object, "screen", sys_info.current_screen);
		return json_serialize_to_string(incoming_value);
	}
	else return NULL;
}

char * get_main_screen_info(char * incoming_string){ //аналогично для side_screen

	JSON_Value * incoming_value = json_parse_string(incoming_string);
	JSON_Object * incoming_object = json_value_get_object(incoming_value);

	char * suitable_symbols = "cels_123456789";

	if(json_object_has_value(incoming_object, "lines_quantity") == HAS_VALUE)
	{

		json_object_set_number(incoming_object, "lines_quantity", main_screen.lines_quantity);
		return json_serialize_to_string(incoming_value);
	}
	else if(strspn (incoming_string, suitable_symbols) == 8){

			JSON_Value *root_value = json_value_init_object();
    		JSON_Object *root_object = json_value_get_object(root_value);

    		char * key_name = NULL;

	}
	else return NULL;
}
