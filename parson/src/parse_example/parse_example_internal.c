#include "parse_example_internal.h"




// void print_parsed_text(void){
// 	printf("%s\n", json_parse_string(string_to_parse));
// }

void print_commits_info(const char *username, const char *repo) {
    JSON_Value *root_value;
    JSON_Array *commits;
    JSON_Object *commit;
    size_t i;
    
    char curl_command[512];
    char cleanup_command[256];
    char output_filename[] = "commits.json";
    
    /* it ain't pretty, but it's not a libcurl tutorial */
    sprintf(curl_command, 
        "curl -s \"https://api.github.com/repos/%s/%s/commits\" > %s",
        username, repo, output_filename);
    sprintf(cleanup_command, "rm -f %s", output_filename);
    system(curl_command);
    
    /* parsing json and validating output */
    root_value = json_parse_file(output_filename);
    if (json_value_get_type(root_value) != JSONArray) {
        system(cleanup_command);
        return;
    }
    
    /* getting array from root value and printing commit info */
    commits = json_value_get_array(root_value);
    printf("%-10.10s %-10.10s %s\n", "Date", "SHA", "Author");
    for (i = 0; i < json_array_get_count(commits); i++) {
        commit = json_array_get_object(commits, i);
        printf("%.10s %.10s %s\n",
               json_object_dotget_string(commit, "commit.author.date"),
               json_object_get_string(commit, "sha"),
               json_object_dotget_string(commit, "commit.author.name"));
    }
    
    /* cleanup code */
    json_value_free(root_value);
    // system(cleanup_command);
}




void serialization_example(void) {
    JSON_Value *root_value = json_value_init_object();
    JSON_Object *root_object = json_value_get_object(root_value);
    char *serialized_string = NULL;

    json_object_set_string(root_object, "Battery type", "Li-Ion");//запись идет в переменную формата JSON_Object
    json_object_set_number(root_object, "Voltage", 15);
    // "...dot_set" создает новый объект, элементами которого являются \
    переменные, поставленные через точку. По сути это как структура

    json_object_dotset_string(root_object, "address.city", "Cupertino");
    json_object_dotset_value(root_object, "contact.emails", json_parse_string("[\"email@example.com\",\"email2@example.com\"]"));

    serialized_string = json_serialize_to_string_pretty(root_value);//перевод JSON в строчку


    puts(serialized_string); //вывод строчки на экран
    json_free_serialized_string(serialized_string);
    json_value_free(root_value);
}
//serialization-преобразования объекта в тип данных (у нас в строку)