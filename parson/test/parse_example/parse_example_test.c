#include "unity_fixture.h"

#include "parse_example_internal.h"
#include "../inc/parse_example/parson.h"

TEST_GROUP (parse_example);

TEST_SETUP (parse_example) {

}

TEST_TEAR_DOWN (parse_example) {

}

TEST (parse_example, start_here) {
	TEST_FAIL_MESSAGE("start test parse_example here");
}


TEST (parse_example, parse_from_file_not_NULL) {
	// print_commits_info("Ryabiko", "command-parser");
	serialization_example();
	TEST_ASSERT_EQUAL_STRING("true",NULL);
}