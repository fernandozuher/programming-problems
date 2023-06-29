// Source: https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_an_int_array(const int size);
char* find_min_loaves_to_satisfy_rules(int* n_loaves_of_each_person, const int size);

int main()
{
    int n_subjects;
    scanf("%d", &n_subjects);

    int* n_loaves_of_each_person = read_an_int_array(n_subjects);

    puts(find_min_loaves_to_satisfy_rules(n_loaves_of_each_person, n_subjects));

    free(n_loaves_of_each_person);
    n_loaves_of_each_person = NULL;

    return 0;
}

    int* read_an_int_array(const int size)
    {
        int* array = (int*) calloc(size, sizeof(int));
        for (int i = 0; i < size; ++i)
            scanf("%d", &array[i]);
        return array;
    }

    char* find_min_loaves_to_satisfy_rules(int* n_loaves_of_each_person, const int size)
    {
        int min_loaves_to_satisfy_rules = 0;

        for (int i = 0, new_size = size - 1; i < new_size; ++i)
            if (n_loaves_of_each_person[i] % 2) {
                n_loaves_of_each_person[i]++;
                n_loaves_of_each_person[i + 1]++;
                min_loaves_to_satisfy_rules += 2;
            }

        if (n_loaves_of_each_person[size - 1] % 2)
            return "NO";

        const int enough_digits = 5;
        char* string = (char*) calloc(enough_digits, sizeof(char));
        sprintf(string, "%d", min_loaves_to_satisfy_rules);
        return string;
    }
