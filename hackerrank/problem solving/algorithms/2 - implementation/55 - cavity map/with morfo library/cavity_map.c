// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true
// C23

#include <stdlib.h>
#include "morfo/io.h"

void change_matrix_to_cavity_map(int n, char *matrix[n]);
bool is_cell_cavity(int n, char *matrix[n], int i, int j);

int main()
{
    int n = morfo_read(int);
    char *matrix[n];
    for (int i = 0; i < n; ++i)
        matrix[i] = morfo_read(char *);

    change_matrix_to_cavity_map(n, matrix);
    morfo_println(matrix, n);

    for (int i = 0; i < n; ++i)
        free(matrix[i]);

    return 0;
}

// n: length of matrix' rows
// T: O(n^2)
// S: O(1) extra space
void change_matrix_to_cavity_map(int n, char *matrix[n])
{
    for (int i = 1, n2 = n - 1; i < n2; ++i)
        for (int j = 1; j < n2; ++j)
            if (is_cell_cavity(n, matrix, i, j))
                matrix[i][j] = 'X';
}

bool is_cell_cavity(int n, char *matrix[n], int i, int j)
{
    char c = matrix[i][j];
    return matrix[i - 1][j] < c &&
           matrix[i][j - 1] < c &&
           matrix[i + 1][j] < c &&
           matrix[i][j + 1] < c;
}
