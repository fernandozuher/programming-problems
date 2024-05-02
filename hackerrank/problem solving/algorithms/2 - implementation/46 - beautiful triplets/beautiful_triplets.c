// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

#include <stdio.h>

int find_beautiful_triplets(const int array[], const int n, const int beautiful_difference);

int main() {
    int n, beautiful_difference;
    scanf("%d %d", &n, &beautiful_difference);
    int array[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &array[i]);

    printf("%d\n", find_beautiful_triplets(array, n, beautiful_difference));

    return 0;
}

    int find_beautiful_triplets(const int array[], const int n, const int beautiful_difference)
    {
        int n_beautiful_triplets = 0;

        if (n > 2)
            for (int i = 0; i < n - 2; ++i)
                for (int j = i + 1; j < n - 1; ++j) {
                    int first_difference = array[j] - array[i];

                    if (first_difference < beautiful_difference)
                        continue;
                    else if (first_difference > beautiful_difference)
                        break;

                    for (int k = j + 1; k < n; ++k) {
                        int second_difference = array[k] - array[j];

                        if (second_difference == beautiful_difference)
                            ++n_beautiful_triplets;
                        else if (second_difference > beautiful_difference)
                            break;
                    }
                }

        return n_beautiful_triplets;
    }
