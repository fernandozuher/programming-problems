// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

Console.ReadLine();
int[] a = ReadNumbers();
int[] b = ReadNumbers();
Console.WriteLine(BetweenTwoSets(a, b));

int[] ReadNumbers() => Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);

int BetweenTwoSets(int[] a, int[] b)
{
    int lcmOfA = a.Aggregate(LCM);
    int gcdOfB = b.Aggregate(GCD);

    int count = 0;
    for (int i = lcmOfA; i <= gcdOfB; i += lcmOfA)
        if (gcdOfB % i == 0)
            count++;
    return count;
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int GCD(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
