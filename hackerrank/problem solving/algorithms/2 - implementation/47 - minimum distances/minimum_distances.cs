// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

Console.ReadLine();
int[] arr = ReadNumbers();
Console.WriteLine(MinDistance(arr));

int[] ReadNumbers() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of array arr
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
