// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

int n = ReadNumbers()[0];
for (int i = 0; i < n; i++)
{
    var line = ReadNumbers();
    int prisoners = line[0], sweets = line[1], startChair = line[2];
    Console.WriteLine(SaveThePrisoner(prisoners, sweets, startChair));
}

int[] ReadNumbers()
{
    return Array.ConvertAll(Console.ReadLine()!.Split(' '), int.Parse);
}

// T: O(1)
// S: O(1) extra space
int SaveThePrisoner(int prisoners, int sweets, int startChair)
{
    return ((startChair - 1 + sweets - 1) % prisoners) + 1;
}
