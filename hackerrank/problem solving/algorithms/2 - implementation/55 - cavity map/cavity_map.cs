// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

public class CavityMap
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine()!);
        char[][] matrix = ReadMatrix(n);
        ChangeMatrixToCavityMap(matrix);
        Array.ForEach(matrix, row => Console.WriteLine(new string(row)));
    }

    private static char[][] ReadMatrix(int n)
    {
        return Enumerable.Range(0, n).Select(_ => Console.ReadLine()!.ToCharArray()).ToArray();
    }

    private static void ChangeMatrixToCavityMap(char[][] matrix)
    {
        for (int i = 1, n = matrix.Length - 1; i < n; i++)
            for (int j = 1; j < n; j++)
                if (IsCellCavity(matrix, i, j))
                    matrix[i][j] = 'X';
    }

    private static bool IsCellCavity(char[][] matrix, int i, int j)
    {
        return matrix[i - 1][j] < matrix[i][j]
            && matrix[i][j - 1] < matrix[i][j]
            && matrix[i + 1][j] < matrix[i][j]
            && matrix[i][j + 1] < matrix[i][j];
    }
}
