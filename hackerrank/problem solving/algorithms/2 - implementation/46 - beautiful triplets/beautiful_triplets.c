// Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int read_a_number();
int* read_an_array(const int size);
int find_beautiful_triplets(const int* array, const int size_array, const int beautiful_difference);

int main()
{
    const int size = read_a_number();
    const int beautiful_difference = read_a_number();
    int* array = read_an_array(size);

    const int n_beautiful_triplets = find_beautiful_triplets(array, size, beautiful_difference);
    printf("%d\n", n_beautiful_triplets);

    free(array);
    array = NULL;

    return 0;
}

    int read_a_number() {
        int number;
        scanf("%d", &number);
        return number;
    }

    int* read_an_array(const int size)
    {
        int* array = (int*) calloc(size, sizeof(int));
        for (int i = 0; i < size; i++)
            scanf("%d", &array[i]);
        return array;
    }

    int find_beautiful_triplets(const int* array, const int size_array, const int beautiful_difference)
    {
        int n_beautiful_triplets = 0;

        if (size_array > 2)
            for (int i = 0; i < size_array - 2; i++)
                for (int j = i + 1; j < size_array - 1; j++)
                {
                    int first_difference = array[j] - array[i];

                    if (first_difference < beautiful_difference)
                        continue;
                    else if (first_difference > beautiful_difference)
                        break;

                    for (int k = j + 1; k < size_array; k++)
                    {
                        int second_difference = array[k] - array[j];

                        if (second_difference == beautiful_difference)
                            n_beautiful_triplets++;
                        else if (second_difference > beautiful_difference)
                            break;
                    }
                }

        return n_beautiful_triplets;
    }
