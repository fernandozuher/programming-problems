// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true
// From C23

#include <stdio.h>
#include <stdlib.h>

int *read_int_array(int n);
int compare(const void *a, const void *b);
int find_most_spotted_bird(int bird_sightings[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    int *array = read_int_array(n);
    qsort(array, n, sizeof(int), compare);
    printf("%d", find_most_spotted_bird(array, n));
    free(array);
    return 0;
}

    int *read_int_array(const int n)
    {
        auto array = (int*) malloc(n * sizeof(int));
        for (int i = 0; i < n; ++i)
            scanf("%d", &array[i]);
        return array;
    }

    int compare(const void *a, const void *b)
    {
        return *(int*) a - *(int*) b;
    }

    int find_most_spotted_bird(int bird_sightings[], const int n)
    {
        int most_spotted_bird = bird_sightings[0];
        int count_most_spotted_bird = 1;
        int temp_count_most_spotted_bird = 1;

        for (int i = 1; i < n; ++i)
            if (bird_sightings[i] == bird_sightings[i - 1])
                ++temp_count_most_spotted_bird;
            else if (temp_count_most_spotted_bird > count_most_spotted_bird) {
                most_spotted_bird = bird_sightings[i - 1];
                count_most_spotted_bird = temp_count_most_spotted_bird;
                temp_count_most_spotted_bird = 1;
            }

        return temp_count_most_spotted_bird > count_most_spotted_bird ? bird_sightings[n - 1] : most_spotted_bird;
    }
