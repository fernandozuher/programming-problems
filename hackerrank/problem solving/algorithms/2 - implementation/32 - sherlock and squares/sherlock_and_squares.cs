// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

int n = ReadNumbers()[0];
for (int i = 0; i < n; i++)
{
    var range = ReadNumbers();
    Console.WriteLine(Squares(range[0], range[1]));
}

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

int Squares(int startNum, int endNum)
{
    int maxSquare = (int)Math.Floor(Math.Sqrt(endNum));
    int minSquare = (int)Math.Ceiling(Math.Sqrt(startNum));
    return maxSquare - minSquare + 1;
}
