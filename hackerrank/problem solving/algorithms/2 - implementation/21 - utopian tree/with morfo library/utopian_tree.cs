// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

using Morfo.IO;

int n = Reader.Read<int>();
int[] utopianTree = GenerateHeightsUtopianTree();
for (int i = 0; i < n; i++)
{
    int cycles = Reader.Read<int>();
    Console.WriteLine(utopianTree[cycles]);
}

// k: length of output = 61
// T: O(k) = O(61) = O(1)
// S: O(61) = O(1) extra space
int[] GenerateHeightsUtopianTree()
{
    const int maxCycles = 60;
    int height = 0;
    return Enumerable.Range(0, maxCycles + 1)
            .Select(cycle => height += IsCycleHappeningDuringSpring(cycle) ? height : 1)
            .ToArray();
}

bool IsCycleHappeningDuringSpring(int cycle) => (cycle & 1) == 1;
