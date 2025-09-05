// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(int *arr, int n);
int jumping_on_the_clouds(const int *clouds, int n, int jump_length);

int main()
{
    int n, jump_length;
    scanf("%d %d", &n, &jump_length);
    int arr[n];
    read_numbers(arr, n);

    printf("%d\n", jumping_on_the_clouds(arr, n, jump_length));

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

int jumping_on_the_clouds(const int *clouds, int n, int jump_length)
{
    int energy = 100;
    int cloud_index = 0;

    do {
        energy -= clouds[cloud_index] == 0 ? 1 : 3;
        cloud_index = (cloud_index + jump_length) % n;
    } while (cloud_index != 0);

    return energy;
}
