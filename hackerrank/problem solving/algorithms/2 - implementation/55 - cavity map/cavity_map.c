// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_matrix(int n, char matrix[n][n + 1]);
void change_matrix_to_cavity_map(int n, char matrix[n][n + 1]);
bool is_cell_cavity(int n, char matrix[n][n + 1], int i, int j);

int main()
{
    int n;
    scanf("%d", &n);
    char matrix[n][n + 1]; // +1 = \0
    read_matrix(n, matrix);

    change_matrix_to_cavity_map(n, matrix);
    for (int i = 0; i < n; ++i)
        puts(matrix[i]);

    return 0;
}

void read_matrix(int n, char matrix[n][n + 1])
{
    for (int i = 0; i < n; ++i)
        scanf("%s", matrix[i]);
}

void change_matrix_to_cavity_map(int n, char matrix[n][n + 1])
{
    for (int i = 1, n2 = n - 1; i < n2; ++i)
        for (int j = 1; j < n2; ++j)
            if (is_cell_cavity(n, matrix, i, j))
                matrix[i][j] = 'X';
}

bool is_cell_cavity(int n, char matrix[n][n + 1], int i, int j)
{
    return matrix[i - 1][j] < matrix[i][j]
           && matrix[i][j - 1] < matrix[i][j]
           && matrix[i + 1][j] < matrix[i][j]
           && matrix[i][j + 1] < matrix[i][j];
}
