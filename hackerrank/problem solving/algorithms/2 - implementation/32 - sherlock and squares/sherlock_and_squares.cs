// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

int n = ReadNumbers()[0];
for (int i = 0; i < n; i++)
{
    var range = ReadNumbers();
    Console.WriteLine(Squares(range[0], range[1]));
}

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// T: O(1)
// S: O(1) extra space
int Squares(int startNum, int endNum)
{
    int maxSquare = (int)Math.Floor(Math.Sqrt(endNum));
    int minSquare = (int)Math.Ceiling(Math.Sqrt(startNum));
    return maxSquare - minSquare + 1;
}
