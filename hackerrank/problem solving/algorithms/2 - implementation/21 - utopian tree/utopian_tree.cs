// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

int n = int.Parse(Console.ReadLine()!);
for (int i = 0; i < n; i++)
{
    int cycles = int.Parse(Console.ReadLine()!);
    Console.WriteLine(UtopianTree(cycles));
}

int UtopianTree(int cycles)
{
    return Enumerable.Range(1, cycles)
                     .Aggregate(1, (height, cycle) => IsCycleHappeningDuringSpring(cycle) ? height * 2 : height + 1);
}

bool IsCycleHappeningDuringSpring(int cycle)
{
    return (cycle & 1) == 1;
}
