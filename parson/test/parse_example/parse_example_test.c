#include "unity_fixture.h"

#include "parse_example_internal.h"
#include "../inc/parse_example/parson.h"

TEST_GROUP (parse_example);

TEST_SETUP (parse_example) {

}

TEST_TEAR_DOWN (parse_example) {

}

TEST (parse_example, example_tests) {
	// print_commits_info("Ryabiko", "command-parser");
	serialization_example();
	// printf("_____________________________\n");
	// persistence_example();
	
	TEST_ASSERT_EQUAL_STRING(NULL, "true");
}

TEST (parse_example, parse_from_file_not_NULL) {
	char * variable = "Date";
	char * value = "Today";
	char * file_name = "Whats_date.json";

	writing_to_file(variable, value, file_name);

	TEST_ASSERT_EQUAL_STRING(NULL,"ы");
}

TEST (parse_example, add_to_object) {
	char * variable = "Name";
	char * value = "Danya";

	edit_object(variable, value);

	variable = "Date";
	value = "Today";

	edit_object(variable, value);

	variable = "Time";
	value = "Now";
	
	edit_object(variable, value);

	variable = "Test from another test";
	value = "everything is cool";

	edit_object(variable, value);

	TEST_ASSERT_EQUAL_STRING(NULL,"s");
}