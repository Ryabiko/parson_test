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
    // printf("\nserailized string: %s\n", serialized_string);

	TEST_ASSERT_EQUAL_STRING(sys_info.current_screen, get_screen(serialized_string));
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

TEST (usable_functions, work_with_cells){

}