// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

// n = test cases
// T = O(n)
// S = O(1)
int n = ReadNumbers()[0];
for (int i = 0; i < n; i++)
{
    var line = ReadNumbers();
    int prisoners = line[0], sweets = line[1], startChair = line[2];
    Console.WriteLine(SaveThePrisoner(prisoners, sweets, startChair));
}

// n = size of elements to be read
// T = O(n)
// S = O(n)
int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(' '), int.Parse);
}

// T = O(1)
// S = O(1)
int SaveThePrisoner(int prisoners, int sweets, int startChair)
{
    return ((startChair - 1 + sweets - 1) % prisoners) + 1;
}
