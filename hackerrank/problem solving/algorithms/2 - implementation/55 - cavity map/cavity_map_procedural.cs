// Source: https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

using System;

public class CavityMap
{
    public static void Main()
    {
        int nRowsColumns = int.Parse(Console.ReadLine());

        List<string> matrix = new List<string>(new string[nRowsColumns]).Select(_ => Console.ReadLine()).ToList();

        _changeMatrixToCavityMap(ref matrix);
        matrix.ForEach(Console.WriteLine);
    }

        private static void _changeMatrixToCavityMap(ref List<string> matrix)
        {
            for (int i = 1, newSize = matrix.Count - 1; i < newSize; i++)
                for (int j = 1; j < newSize; j++)
                    if (_isCellCavity(ref matrix, i, j))
                        matrix[i] = _generateStringWithCavity(matrix[i], j);
        }

            private static bool _isCellCavity(ref List<string> matrix, int i, int j)
            {
                return matrix[i - 1][j] < matrix[i][j]
                       && matrix[i][j - 1] < matrix[i][j]
                       && matrix[i + 1][j] < matrix[i][j]
                       && matrix[i][j + 1] < matrix[i][j];
            }

            private static string _generateStringWithCavity(string line, int indexToPutCavity) {
                const char cavity = 'X';
                char[] stringToChar = line.ToCharArray();
                stringToChar[indexToPutCavity] = cavity;
                return new string(stringToChar);
            }
}
