// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

int lower = int.Parse(Console.ReadLine()!);
int upper = int.Parse(Console.ReadLine()!);
bool validRange = false;

for (int num = lower; num <= upper; num++)
    if (IsNumberKaprekar(num))
    {
        Console.Write(num + " ");
        validRange = true;
    }

if (!validRange)
    Console.WriteLine("INVALID RANGE");

bool IsNumberKaprekar(int n)
{
    long squareNumber = (long)Math.Pow(n, 2);
    long divisor = (long)Math.Pow(10, NumberDigits(n));
    long leftNumber = Math.DivRem(squareNumber, divisor, out long rightNumber);
    return n == leftNumber + rightNumber;
}

int NumberDigits(long n)
{
    return n.ToString().Length;
}
