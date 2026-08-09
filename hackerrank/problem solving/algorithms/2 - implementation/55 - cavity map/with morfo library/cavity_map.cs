// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

using Morfo.IO;

int n = Reader.Read<int>();
char[][] matrix = ReadMatrix(n);
ChangeMatrixToCavityMap(matrix);
Writer.Println(matrix.Select(x => new string(x)));

char[][] ReadMatrix(int n) => Enumerable.Range(0, n).Select(_ => Reader.Read<string>().ToCharArray()).ToArray();

// n: length of matrix' rows
// T: O(n^2)
// S: O(1) extra space
void ChangeMatrixToCavityMap(char[][] matrix)
{
    for (int i = 1, n = matrix.Length - 1; i < n; i++)
        for (int j = 1; j < n; j++)
            if (IsCellCavity(matrix, i, j))
                matrix[i][j] = 'X';
}

bool IsCellCavity(char[][] matrix, int i, int j)
{
    char c = matrix[i][j];
    return matrix[i - 1][j] < c &&
           matrix[i][j - 1] < c &&
           matrix[i + 1][j] < c &&
           matrix[i][j + 1] < c;
}
