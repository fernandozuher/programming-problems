// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true
// From C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float *plus_minus(int n);
    float *wrap_result(const float array[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    float *result = plus_minus(n);
    printf("%.6f\n%.6f\n%.6f", result[0], result[1], result[2]);
    free(result);

    return 0;
}

    float *plus_minus(const int n)
    {
        int positive = 0, negative = 0, zero = 0;

        for (int i = 0, x; i < n && scanf("%d", &x); ++i)
            if (x > 0)
                ++positive;
            else if (x < 0)
                ++negative;
            else
                ++zero;

        float positive_proportion = (float) positive / n;
        float negative_proportion = (float) negative / n;
        float zero_proportion = (float) zero / n;

        constexpr int n_result = 3;
        float temp_result[] = {positive_proportion, negative_proportion, zero_proportion};
        return wrap_result(temp_result, n_result);
    }

        float *wrap_result(const float array[], const int n)
        {
            auto result = (float*) malloc(n * sizeof(float));
            memcpy(result, array, n * sizeof(float));
            return result;
        }
