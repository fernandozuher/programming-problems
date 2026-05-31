// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

var matrix = ReadMatrix();
Console.WriteLine(MaxHourglassSum(matrix));

int[][] ReadMatrix()
{
    var matrix = new int[6][];
    for (int i = 0; i < 6; i++)
        matrix[i] = ReadNumbers();
    return matrix;
}

int[] ReadNumbers()
{
    return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
}

// T: O(1)
// S: O(1) extra space
int MaxHourglassSum(int[][] matrix)
{
    int maxSum = Int32.MinValue;

    for (int i = 1, rowsCols = 4; i <= rowsCols; i++)
        for (int j = 1; j <= rowsCols; j++)
        {
            int currentSum = HourglassSum(matrix, i, j);
            maxSum = Math.Max(maxSum, currentSum);
        }

    return maxSum;
}

int HourglassSum(int[][] matrix, int i, int j)
{
    int subrow1FirstIndex = i - 1;
    int subrow3FirstIndex = i + 1;
    int firstColIndex = j - 1;

    int subrow1Sum = matrix[subrow1FirstIndex][firstColIndex] + matrix[subrow1FirstIndex][firstColIndex + 1] + matrix[subrow1FirstIndex][firstColIndex + 2];
    int subrow3Sum = matrix[subrow3FirstIndex][firstColIndex] + matrix[subrow3FirstIndex][firstColIndex + 1] + matrix[subrow3FirstIndex][firstColIndex + 2];

    return subrow1Sum + matrix[i][j] + subrow3Sum;
}
