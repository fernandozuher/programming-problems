// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

int n = ReadNumber();
for (int i = 0; i < n; i++)
    Console.WriteLine(FindDigits(ReadNumber()));

int ReadNumber()
{
    return int.Parse(Console.ReadLine()!);
}

int FindDigits(int n)
{
    return n.ToString().ToCharArray().Select(c => c - '0').Count(d => d != 0 && n % d == 0);
}
