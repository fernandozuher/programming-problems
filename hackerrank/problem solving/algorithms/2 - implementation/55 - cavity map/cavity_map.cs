// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true
// From C# 8.0

using static System.Console;

class CavityMap
{
    static void Main()
    {
        int nRowsColumns = int.Parse(Console.ReadLine());
        var matrix = new List<string>(new string[nRowsColumns]).Select(_ => ReadLine()).ToList();
        ChangeMatrixToCavityMap(matrix);
        matrix.ForEach(WriteLine);
    }

        static void ChangeMatrixToCavityMap(List<string> matrix)
        {
            if (3 is var minInputToLookForCavity && matrix.Count < minInputToLookForCavity)
                return;

            var range = Enumerable.Range(1, matrix.Count - 2);
            foreach (int i in range)
                foreach (int j in range)
                    if (IsCellCavity(matrix, i, j))
                        matrix[i] = GenerateStringWithCavity(matrix[i], j);
        }

            static bool IsCellCavity(List<string> matrix, int i, int j)
            {
                return matrix[i - 1][j] < matrix[i][j]
                    && matrix[i][j - 1] < matrix[i][j]
                    && matrix[i + 1][j] < matrix[i][j]
                    && matrix[i][j + 1] < matrix[i][j];
            }

            static string GenerateStringWithCavity(string line, int i)
            {
                const char cavity = 'X';
                char[] stringToChar = line.ToCharArray();
                stringToChar[i] = cavity;
                return new string(stringToChar);
            }
}
