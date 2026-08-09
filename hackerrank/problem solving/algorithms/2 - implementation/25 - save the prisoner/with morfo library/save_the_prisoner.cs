// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

using Morfo.IO;

int n = Reader.Read<int>();
for (int i = 0; i < n; i++)
{
    int prisoners = Reader.Read<int>();
    int sweets = Reader.Read<int>();
    int startChair = Reader.Read<int>();
    Console.WriteLine(SaveThePrisoner(prisoners, sweets, startChair));
}

// T: O(1)
// S: O(1) extra space
int SaveThePrisoner(int prisoners, int sweets, int startChair) => ((startChair - 1 + sweets - 1) % prisoners) + 1;
