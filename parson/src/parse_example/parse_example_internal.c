#include "parse_example_internal.h"





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



//в этой функции мы создаем объект json, а потом переводим его в читабельную строку
void serialization_example(void) {//serialization-преобразование объекта в тип данных (у нас в строку)
    JSON_Value *root_value = json_value_init_object();
    JSON_Object *root_object = json_value_get_object(root_value);

    char *serialized_string = NULL;

    json_object_set_string(root_object, "Battery type", "Li-Ion");//запись идет в переменную формата JSON_Object
    json_object_set_number(root_object, "Voltage", 15);
    // "...dot_set" создает новый объект, элементами которого являются \
    переменные, поставленные через точку. По сути это как структура
    json_object_dotset_string(root_object, "address.city", "Cupertino");
    json_object_dotset_string(root_object, "address.street", "Esenina");
    json_object_dotset_value(root_object, "contact.emails", json_parse_string("[\"email@example.com\",\"email2@example.com\"]"));

    serialized_string = json_serialize_to_string_pretty(root_value);//перевод из JSON в строчку



    puts(serialized_string); //вывод строчки на экран  

    printf("%s\n------------\n\n", json_object_dotget_string(root_object, "address.city"));//доступ к строчке файла json

    json_free_serialized_string(serialized_string);
    json_value_free(root_value);

}



void persistence_example(void) { //создается файл с данными о пользователе
    JSON_Value *schema = json_parse_string("{\"name\":\"\"}");
    JSON_Value *user_data = json_parse_file("user_data.json");

    char buf[256];
    const char *name = NULL;
    if (user_data == NULL || json_validate(schema, user_data) != JSONSuccess)//проверка, есть ли такой файл \
    																		   и есть ли такое поле в нём 
    {
        puts("Enter your name:");
        scanf("%s", buf);
        user_data = json_value_init_object();
        json_object_set_string(json_object(user_data), "name", buf);// в значение name объекта user_data  \
        																ставится значение, лежащее в buf
        json_serialize_to_file(user_data, "user_data.json");//запись получившегося в файл\
        													если файла с таким названием нет, он создается
    }


    // json_object_set_string(json_object(user_data), "Age", "20");
    // json_serialize_to_file(user_data, "new_file.json");


    name = json_object_get_string(json_object(user_data), "name");
    printf("Hello, %s.", name);
    json_value_free(schema);
    json_value_free(user_data);
    return;
}

void writing_to_file(char * variable, char * value, char * file_name){

	// JSON_Value * data = json_parse_file(file_name);//parse_file если надо посмотреть, есть ли уже данные в файле
	JSON_Value *data = json_value_init_object();

	json_object_set_string(json_object(data), variable, value);
	json_serialize_to_file(data, file_name);

	data_string = json_serialize_to_string_pretty(data);//сохранение в глобальную переменную\
														можно сделать функцию, выдающую строку

	puts(json_serialize_to_string_pretty(json_parse_file(file_name)));

}

void add_to_object(JSON_Object *object, char * variable, char * value){
	JSON_Value * j_value = NULL;


	if (json_object_has_value(object, variable)!= NO_VALUE){
		json_object_set_string(object, variable, value);

		j_value = json_value_init_object();
        json_object_set_string(json_object(j_value), variable, value);
	}
	// json_serialize_to_file(value, "add_to_object.json");


	// puts(object);
}
 

 /*как осуществляется процесс передачи вообще, и ,соответственно, какие методы нам будут нужны: 
 1.Можем сохранять в глобальную переменную (что не очень хорошо) 
 2.Можем сохранять в файл
 
 Также вопрос, какие данные передаются: фиксированные или каво?*/