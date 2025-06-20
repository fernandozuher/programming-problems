// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

void read_numbers(int numbers[], int n);
int compare(const void *a, const void *b);
int find_most_spotted_bird(int birds[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    int birds[n];
    read_numbers(birds, n);
    qsort(birds, n, sizeof(int), compare);
    printf("%d", find_most_spotted_bird(birds, n));
    return 0;
}

void read_numbers(int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
}

int compare(const void *a, const void *b)
{
    return *(int*) a - *(int*) b;
}

int find_most_spotted_bird(int birds[], int n)
{
    int most_spotted_bird = birds[0];
    int max_count = 1;
    int count = 1;

    for (int i = 1; i < n; ++i)
        if (birds[i] == birds[i - 1])
            ++count;
        else if (count > max_count) {
            most_spotted_bird = birds[i - 1];
            max_count = count;
            count = 1;
        }

    return count > max_count ? birds[n - 1] : most_spotted_bird;
}
