#ifndef _PARSE_EXAMPLE_INTERNAL_H_
#define _PARSE_EXAMPLE_INTERNAL_H_

#include "parse_example.h"

#define NO_VALUE 0


void print_parsed_text(void);

void print_commits_info(const char *username, const char *repo);
void serialization_example(void);
void persistence_example(void);
void writing_to_file(char * variable, char * value, char * file_name);
void add_to_object(char * variable, char * value);
void edit_object(char * variable, char * value);

// JSON_Value *global_value = json_value_init_object();;
// JSON_Object * global_object = json_value_get_object(global_value);



#endif//_PARSE_EXAMPLE_INTERNAL_H_

