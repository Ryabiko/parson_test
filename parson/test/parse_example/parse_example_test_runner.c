#include "unity_fixture.h"

TEST_GROUP_RUNNER (parse_example) {
	RUN_TEST_CASE (parse_example, example_tests);
	RUN_TEST_CASE (parse_example, parse_from_file_not_NULL);
	RUN_TEST_CASE (parse_example, add_to_object);
}

