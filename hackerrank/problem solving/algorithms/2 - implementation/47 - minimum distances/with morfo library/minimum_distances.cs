// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

using Morfo.IO;

Reader.SkipInputLn();
int[] arr = Reader.ReadLn<int, int[]>();
Console.WriteLine(MinDistance(arr));

// n: length of arr
// T: O(n)
// S: O(n) extra space
int MinDistance(int[] arr)
{
    var lastSeen = new Dictionary<int, int>();
    int minDist = -1;

    for (int i = 0; i < arr.Length; i++)
    {
        int x = arr[i];
        if (lastSeen.ContainsKey(x))
        {
            int dist = i - lastSeen[x];
            if (minDist == -1 || dist < minDist)
            {
                minDist = dist;
                if (minDist == 1)
                    return 1;
            }
        }
        lastSeen[x] = i;
    }

    return minDist;
}
