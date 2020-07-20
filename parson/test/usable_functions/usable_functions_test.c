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
    char * serialized_string = json_serialize_to_string_pretty(screen_value);

	TEST_ASSERT_EQUAL_STRING("{\"lines_quantity\":33}", get_main_screen_info(serialized_string));
}

TEST (usable_functions, taking_name_from_json_string){

	char * testing_str = "{\"screen\":\"main\"}";
	printf("\ntaken key: %s\n", get_key_from_str(testing_str));



	// TEST_ASSERT_EQUAL_STRING("screen", get_key_from_str(testing_str));
}