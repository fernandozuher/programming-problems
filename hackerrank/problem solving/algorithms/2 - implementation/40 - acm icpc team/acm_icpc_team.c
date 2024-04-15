// https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **read_strings(const int n, const int size_string);
int *find_maximum_subjects_and_teams_that_know_them(char **binary_strings, const int n);
    int count_subjects_known_by_2_teams(char *binary_string_1, char *binary_string_2);
    void update_maximum_subjects_and_teams_that_know_them(
        const int subjects_known_by_2_teams,
        int *maximum_subjects_known_by_teams,
        int *teams_that_know_maximum_subjects);
void print_array(const int *array, const int size);
char **free_string_array(char **array, int n);

int main()
{
    int attendees, topics;
    scanf("%d %d", &attendees, &topics);
    char **binary_strings = read_strings(attendees, topics);

    int *output = find_maximum_subjects_and_teams_that_know_them(binary_strings, attendees);
    print_array(output, 2);

    binary_strings = free_string_array(binary_strings, attendees);
    free(output);
    output = NULL;

    return 0;
}

    char **read_strings(const int n, const int size_string)
    {
        char **array = (char**) calloc(n, sizeof(char*));
        for (int i = 0; i < n; ++i) {
            array[i] = (char*) calloc(size_string + 1, sizeof(char)); // + \0
            scanf("%s", array[i]);
        }
        return array;
    }

    int *find_maximum_subjects_and_teams_that_know_them(char **binary_strings, const int n)
    {
        int maximum_subjects_known_by_teams = 0;
        int teams_that_know_maximum_subjects = 0;

        for (int i = 0, n1 = n - 1; i < n1; ++i)
            for (int j = i + 1; j < n; ++j) {
                int subjects_known_by_2_teams = count_subjects_known_by_2_teams(binary_strings[i], binary_strings[j]);
                update_maximum_subjects_and_teams_that_know_them(subjects_known_by_2_teams, &maximum_subjects_known_by_teams, &teams_that_know_maximum_subjects);
            }

        int *output = (int*) calloc(2, sizeof(int));
        output[0] = maximum_subjects_known_by_teams;
        output[1] = teams_that_know_maximum_subjects;

        return output;
    }

        int count_subjects_known_by_2_teams(char *binary_string_1, char *binary_string_2)
        {
            int subjects_known_by_2_teams = 0;
            for (int i = 0, n = strlen(binary_string_1); i < n; ++i)
                if (binary_string_1[i] == '1' || binary_string_2[i] == '1')
                    ++subjects_known_by_2_teams;
            return subjects_known_by_2_teams;
        }

        void update_maximum_subjects_and_teams_that_know_them(
            const int subjects_known_by_2_teams,
            int *maximum_subjects_known_by_teams,
            int *teams_that_know_maximum_subjects)
        {
            if (subjects_known_by_2_teams > *maximum_subjects_known_by_teams) {
                *maximum_subjects_known_by_teams = subjects_known_by_2_teams;
                *teams_that_know_maximum_subjects = 1;
            }
            else if (subjects_known_by_2_teams == *maximum_subjects_known_by_teams)
                ++(*teams_that_know_maximum_subjects);
        }

    void print_array(const int *array, const int n)
    {
        for (int i = 0; i < n; printf("%d\n", array[i++]));
    }

    char **free_string_array(char **array, int n)
    {
        for (; n--; free(array[n]));
        free(array);
        return NULL;
    }
