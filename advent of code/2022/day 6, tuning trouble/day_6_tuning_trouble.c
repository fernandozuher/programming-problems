#include <stdio.h>
#include <stdlib.h> //calloc(), exit(), qsort()
#include <string.h> //strlen(), strcpy(), strncpy(), strtok()
#include <stdbool.h>

void tuning_trouble(const char **input, const int n);
    int count_characters_before_end_of_some_maker(const char **input, const int size_packet);
        char* get_substring(const char **input, const int initial_index, const int current_index, const int size_packet);
        bool is_substring_like_a_set(char *substring);
            int compare (const void *a, const void *b);


char** read_input_from_file(int input_lines, int *n, int expected_max_input_size) {
    FILE *fp = fopen("input.txt", "r");

    if (!fp) {
        printf("\nError in opening file.\n");
        exit(EXIT_FAILURE);
    }

    int max_size = expected_max_input_size;
    char **input = (char**) calloc(input_lines, sizeof(char*));

    for (char temp_string[max_size]; fgets(temp_string, max_size, fp); (*n)++) {
        input[*n] = (char*) calloc(max_size, sizeof(char));
        strcpy(input[*n], temp_string);
    }

    fclose(fp);
    return input;
}

void tuning_trouble(const char **input, const int n) {
    int characters_before_end_of_packet_maker = count_characters_before_end_of_some_maker(input, 4);
    int characters_before_end_of_message_maker = count_characters_before_end_of_some_maker(input, 14);
    printf("%d\n%d\n", characters_before_end_of_packet_maker, characters_before_end_of_message_maker);
}

    int count_characters_before_end_of_some_maker(const char **input, const int size_packet) {
        int initial_index = size_packet - 1;
        int last_index_of_some_maker = -1;
        for (int i = initial_index, n = strlen(input[0]); i < n; i++) {
            char *substring = get_substring(input, initial_index, i, size_packet);
            
            if (is_substring_like_a_set(substring)) {
                last_index_of_some_maker = i;
                break;
            }
        }
        return last_index_of_some_maker + 1;
    }

        char* get_substring(const char **input, const int initial_index, const int current_index, const int size_packet) {
            char *substring = (char*) calloc(size_packet + 1, sizeof(char));
            strncpy(substring, (input[0] + current_index - initial_index), size_packet);
            substring[size_packet] = '\0';
            return substring;
        }

        bool is_substring_like_a_set(char *substring) {
            qsort(substring, strlen(substring), sizeof(char), compare);
            for (int i = 1, n = strlen(substring); i < n; i++)
                if (substring[i - 1] == substring[i])
                    return false;
            return true;
        }

            int compare (const void *a, const void *b) {
                return *(char*)a - *(char*)b;
            }


int main() {
    int input_lines = 1;
    int expected_max_input_size = 4098;
    int input_data_n = 0;

    const char **input = (const char**) read_input_from_file(input_lines, &input_data_n, expected_max_input_size);
    tuning_trouble(input, input_data_n);
    return 0;
}
