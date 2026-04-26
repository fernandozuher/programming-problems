// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

Console.ReadLine();
Dictionary<int, int> socksToCounts = Counter(ReadNumbers());
Console.WriteLine(SockMerchant(socksToCounts));

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(k) extra space
Dictionary<int, int> Counter(int[] arr)
{
    var freqMap = new Dictionary<int, int>();
    foreach (var x in arr)
    {
        freqMap.TryGetValue(x, out int count);
        freqMap[x] = ++count;
    }
    return freqMap;
}

int[] ReadNumbers()
{
    return Console.ReadLine()!.Split().Select(int.Parse).ToArray();
}

// k: length of entries in socksToCounts
// T: O(k)
// S: O(1) extra space
int SockMerchant(Dictionary<int, int> socksToCounts) => socksToCounts.Values.Sum(x => x / 2);
