// Source: https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_line_as_int_array(const int n);
int compare (const void *a, const void *b);
int migratory_birds(int *bird_sightings, const int n);

int main() {
    const int *array_size = read_line_as_int_array(1);
    const int n = array_size[0];
    int *bird_sightings = read_line_as_int_array(n);

    qsort(bird_sightings, n, sizeof(int), compare);

    const int result = migratory_birds(bird_sightings, n);
    printf("%d\n", result);

    return 0;
}

    int* read_line_as_int_array(const int n) {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &array[i]);
        return array;
    }

    int compare (const void *a, const void *b) {
        return (*(int*) a - *(int*) b);
    }

    int migratory_birds(int *bird_sightings, const int n) {
        int most_spotted_bird = bird_sightings[0];
        int count_most_spotted_bird = 1;
        int temp_count_most_spotted_bird = 1;

        for (int i = 1; i < n; i++)

            if (bird_sightings[i] == bird_sightings[i - 1])
                temp_count_most_spotted_bird++;

            else if (temp_count_most_spotted_bird > count_most_spotted_bird) {
                most_spotted_bird = bird_sightings[i - 1];
                count_most_spotted_bird = temp_count_most_spotted_bird;
                temp_count_most_spotted_bird = 1;
            }

        if (temp_count_most_spotted_bird > count_most_spotted_bird)
            most_spotted_bird = bird_sightings[n - 1];

        return most_spotted_bird;
    }
