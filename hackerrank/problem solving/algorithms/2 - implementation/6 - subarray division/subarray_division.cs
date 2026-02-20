// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

Console.ReadLine();
int[] chocolateSquares = ReadNumbers();
int[] dayMonth = ReadNumbers();
Console.WriteLine(Birthday(chocolateSquares, dayMonth));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of array chocolateSquares
// 1 <= n <= 100
// T: O(n) = O(100) = O(1)
// S: O(1) extra space
int Birthday(int[] chocolateSquares, int[] dayMonth)
{
    int day = dayMonth[0];
    int month = dayMonth[1];

    if (month > chocolateSquares.Length)
        return 0;

    int sum = chocolateSquares.Take(month).Sum();
    int count = sum == day ? 1 : 0;

    for (int i = month; i < chocolateSquares.Length; i++)
    {
        sum += chocolateSquares[i] - chocolateSquares[i - month];
        if (sum == day)
            count++;
    }

    return count;
}
