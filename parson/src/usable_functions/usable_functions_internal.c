#include "usable_functions_internal.h"

char * free_symbols (char * source) {
	char * delimeters = "\"{:\n\t ";
	int del_quantity = strspn(source, delimeters);
    return source + del_quantity;
}



char * get_key_from_str(char * key){
	char * 	suitable_symbols = "abcdefghijklmnopqrstuvwxyz_1234567890",
		 *	middle_string = free_symbols(key);

	int sym_quantity = strspn(middle_string, suitable_symbols);

	char *	returning_string = malloc(sym_quantity/2);//extracting of memory for variable

	strncpy (returning_string, middle_string, sym_quantity);

	return returning_string;
}

int get_cell(int position, char * key){
	if(position == X){
		return atoi(&key[5]);
	}
	else if(position == X){
		return atoi(&key[7]);
	}
}


char * get_screen(char * incoming_string){
	JSON_Value * incoming_value = json_parse_string(incoming_string);
	JSON_Object * incoming_object = json_value_get_object(incoming_value);

	if (json_object_has_value(incoming_object, "screen") == HAS_VALUE){
		json_object_set_string(incoming_object, "screen", sys_info.current_screen);
		return json_serialize_to_string(incoming_value);
	}
	else return NULL;
}

char * get_main_screen_info(char * incoming_string){ //аналогично для side_screen

	JSON_Value * incoming_value = json_parse_string(incoming_string);
	JSON_Object * incoming_object = json_value_get_object(incoming_value);

	char *	suitable_symbols = "cels_123456789",
		 *	incoming_key = get_key_from_str(incoming_string);
	printf("%s\n", incoming_key);
	if(json_object_has_value(incoming_object, "lines_quantity") == HAS_VALUE){

		json_object_set_number(incoming_object, "lines_quantity", main_screen.lines_quantity);
		return json_serialize_to_string(incoming_value);
	}
	else if(strspn (incoming_string, suitable_symbols) == 8){

    	json_object_set_number(incoming_object, "some_cell", \
    		main_screen.cells[ get_cell(X, incoming_key) ][ get_cell(Y, incoming_key) ]);
		return json_serialize_to_string(incoming_value);

		return NULL;
	}
	else return NULL;
}
