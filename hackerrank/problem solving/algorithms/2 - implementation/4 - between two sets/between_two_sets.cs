// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

Console.ReadLine();
int[] a = ReadNumbers();
int[] b = ReadNumbers();
Console.WriteLine(BetweenTwoSets(a, b));

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(), int.Parse);
}

int BetweenTwoSets(int[] a, int[] b)
{
    int lcmOfA = LcmArray(a);
    int gcdOfB = GcdArray(b);

    int count = 0;
    for (int i = lcmOfA; i <= gcdOfB; i += lcmOfA)
        if (gcdOfB % i == 0)
            count++;
    return count;
}

int LcmArray(int[] arr)
{
    return arr.Aggregate(Lcm);
}

int Lcm(int a, int b)
{
    return a * b / Gcd(a, b);
}

int GcdArray(int[] arr)
{
    return arr.Aggregate(Gcd);
}

int Gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
