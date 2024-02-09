// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* read_int_array(const int n);
int jumping_on_clouds(const int* const clouds, const int n, const int jump_length);
    int spent_energy_according_to_type_of_cloud(const int cloud_type);
    int generate_new_cloud_index(const int cloud_index, const int n, const int jump_length);
    bool is_cloud_index_back_to_first_cloud(const int cloud_index);

int main()
{
    int n, jump_length;
    scanf("%d %d", &n, &jump_length);
    int *array = read_int_array(n);
    printf("%d\n", jumping_on_clouds(array, n, jump_length));

    free(array);
    array = NULL;

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    int jumping_on_clouds(const int* const clouds, const int n, const int jump_length)
    {
        int energy = 100;

        for (int cloud_index = 0; true;) {
            energy -= spent_energy_according_to_type_of_cloud(clouds[cloud_index]);
            cloud_index = generate_new_cloud_index(cloud_index, n, jump_length);
            if (is_cloud_index_back_to_first_cloud(cloud_index))
                break;
        }

        return energy;
    }

        int spent_energy_according_to_type_of_cloud(const int cloud_type)
        {
            return cloud_type == 0 ? 1 : 3;
        }

        int generate_new_cloud_index(const int cloud_index, const int n, const int jump_length)
        {
            return (cloud_index + jump_length) % n;
        }

        bool is_cloud_index_back_to_first_cloud(const int cloud_index)
        {
            return cloud_index == 0;
        }
