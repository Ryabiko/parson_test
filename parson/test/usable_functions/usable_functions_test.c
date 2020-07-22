#include "unity_fixture.h"

#include "usable_functions_internal.h"

TEST_GROUP (usable_functions);

TEST_SETUP (usable_functions) {

}

TEST_TEAR_DOWN (usable_functions) {

}


TEST (usable_functions, checking_screen){
	sys_info.current_screen = "main";

	JSON_Value *screen_value = json_value_init_object();
    JSON_Object *screen_object = json_value_get_object(screen_value);
    
    json_object_set_string(screen_object, "screen", "some_type");
    char * serialized_string = json_serialize_to_string_pretty(screen_value);

	TEST_ASSERT_EQUAL_STRING("{\"screen\":\"main\"}", get_screen(serialized_string));
}

TEST (usable_functions, sent_not_screen_string){
	sys_info.current_screen = "main";

	JSON_Value *screen_value = json_value_init_object();
    JSON_Object *screen_object = json_value_get_object(screen_value);
    
    json_object_set_number(screen_object, "voltage_cut_off", 220);
    char * serialized_string = json_serialize_to_string_pretty(screen_value);
    // printf("\nserailized string: %s\n", serialized_string);

	TEST_ASSERT_EQUAL_STRING(NULL, get_screen(serialized_string));
}

TEST (usable_functions, lines_quantity_test){
	main_screen.lines_quantity = 33;

	JSON_Value *screen_value = json_value_init_object();
    JSON_Object *screen_object = json_value_get_object(screen_value);
    
    json_object_set_number(screen_object, "lines_quantity", 0);
    char * serialized_string = json_serialize_to_string(screen_value);

	TEST_ASSERT_EQUAL_STRING("{\"lines_quantity\":33}", get_main_screen_info(serialized_string));
}

TEST (usable_functions, taking_name_from_json_string_screen){


	JSON_Value *screen_value = json_value_init_object();
    JSON_Object *screen_object = json_value_get_object(screen_value);
    
    json_object_set_string(screen_object, "screen", "side");
    char * testing_str = json_serialize_to_string_pretty(screen_value);

	TEST_ASSERT_EQUAL_STRING("screen", get_key_from_str(testing_str));
}

TEST (usable_functions, taking_name_from_json_string_cells){

	JSON_Value *screen_value = json_value_init_object();
    JSON_Object *screen_object = json_value_get_object(screen_value);
    
    json_object_set_string(screen_object, "2_4_cells", "filling");
    char * testing_str = json_serialize_to_string(screen_value);//doesn't work pretty serialization

	TEST_ASSERT_EQUAL_STRING("2_4_cells", get_key_from_str(testing_str));
}

TEST (usable_functions, get_cells){

	char * cell_2_4 = "cell_2_4";

	TEST_ASSERT_EQUAL_INT(2, get_cell(X, cell_2_4));
}

TEST (usable_functions, get_celll_info){


	TEST_ASSERT_EQUAL_INT(2, 0);
}