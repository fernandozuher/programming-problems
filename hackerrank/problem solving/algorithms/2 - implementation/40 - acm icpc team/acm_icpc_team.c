// Source: https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int read_a_number();
char** read_binary_strings(const int N_STRINGS, const int SIZE_STRING);
    char* read_a_string(const int SIZE);

int* find_maximum_subjects_and_teams_that_know_them(char** binary_strings, const int SIZE_ARRAY);
    int count_subjects_known_by_2_teams(char* binary_string_1, char* binary_string_2);
    void update_maximum_subjects_and_teams_that_know_them(const int SUBJECTS_KNOWN_BY_2_TEAMS, int* maximum_subjects_known_by_teams, int* teams_that_know_maximum_subjects);

void print_array(const int* array, const int SIZE);
char** free_strings_array(char** array, const int SIZE);
int* free_int_array(int* array);


int main() {
    const int ATTENDEES = read_a_number();
    const int TOPICS = read_a_number();
    char** binary_strings = read_binary_strings(ATTENDEES, TOPICS);

    int* output = find_maximum_subjects_and_teams_that_know_them(binary_strings, ATTENDEES);
    print_array(output, 2);

    binary_strings = free_strings_array(binary_strings, ATTENDEES);
    output = free_int_array(output);

    return 0;
}

    int read_a_number() {
        int number;
        scanf("%d", &number);
        return number;
    }

    char** read_binary_strings(const int N_STRINGS, const int SIZE_STRING) {
        char** binary_strings = (char**) calloc(N_STRINGS, sizeof(char*));

        for (int i = 0; i < N_STRINGS; i++)
            binary_strings[i] = read_a_string(SIZE_STRING);

        return binary_strings;
    }

        char* read_a_string(const int SIZE) {
            char* string = (char*) calloc(SIZE + 1, sizeof(char));
            scanf("%s", string);
            return string;
        }

    int* find_maximum_subjects_and_teams_that_know_them(char** binary_strings, const int SIZE_ARRAY) {
        int maximum_subjects_known_by_teams = 0;
        int teams_that_know_maximum_subjects = 0;

        for (int i = 0; i < SIZE_ARRAY - 1; i++) {
            for (int j = i + 1; j < SIZE_ARRAY; j++) {
                const int SUBJECTS_KNOWN_BY_2_TEAMS = count_subjects_known_by_2_teams(binary_strings[i], binary_strings[j]);
                update_maximum_subjects_and_teams_that_know_them(SUBJECTS_KNOWN_BY_2_TEAMS, &maximum_subjects_known_by_teams, &teams_that_know_maximum_subjects);
            }
        }

        int* output = (int*) calloc(2, sizeof(int));
        output[0] = maximum_subjects_known_by_teams;
        output[1] = teams_that_know_maximum_subjects;

        return output;
    }

        int count_subjects_known_by_2_teams(char* binary_string_1, char* binary_string_2) {
            int subjects_known_by_2_teams = 0;

            for (int i = 0; binary_string_1[i] != '\0'; i++)
                if (binary_string_1[i] == '1' || binary_string_2[i] == '1')
                    subjects_known_by_2_teams++;

            return subjects_known_by_2_teams;
        }

        void update_maximum_subjects_and_teams_that_know_them(const int SUBJECTS_KNOWN_BY_2_TEAMS, int* maximum_subjects_known_by_teams, int* teams_that_know_maximum_subjects) {
            if (SUBJECTS_KNOWN_BY_2_TEAMS > *maximum_subjects_known_by_teams) {
                *maximum_subjects_known_by_teams = SUBJECTS_KNOWN_BY_2_TEAMS;
                *teams_that_know_maximum_subjects = 1;
            }
            else if (SUBJECTS_KNOWN_BY_2_TEAMS == *maximum_subjects_known_by_teams)
                (*teams_that_know_maximum_subjects)++;
        }

    void print_array(const int* array, const int SIZE) {
        for (int i = 0; i < SIZE; printf("%d\n", array[i++]));
    }

    char** free_strings_array(char** array, const int SIZE) {
        for (int i = 0; i < SIZE; i++)
            free(array[i]);

        free(array);
        return NULL;
    }

    int* free_int_array(int* array) {
        free(array);
        return NULL;
    }
