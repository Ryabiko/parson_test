#include "unity_fixture.h"

TEST_GROUP_RUNNER (usable_functions) {
	RUN_TEST_CASE (usable_functions, checking_screen);
	RUN_TEST_CASE (usable_functions, sent_not_screen_string);
	RUN_TEST_CASE (usable_functions, work_with_cells)
}

