// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

Console.ReadLine();
Dictionary<int, int> socksToCounts = Counter();
Console.WriteLine(SockMerchant(socksToCounts));

// n: length of user input
// k: length of distinct numbers in user input
// T: O(n)
// S: O(n) extra space
Dictionary<int, int> Counter()
{
    var freqMap = new Dictionary<int, int>();
    foreach (var x in Console.ReadLine()!.Split().Select(int.Parse))
    {
        freqMap.TryGetValue(x, out int count);
        freqMap[x] = ++count;
    }
    return freqMap;
}

// n: length of initial user input
// k: length of entries in socksToCounts
// k <= n
// T: O(k)
// S: O(1) extra space
int SockMerchant(Dictionary<int, int> socksToCounts) => socksToCounts.Values.Select(x => x / 2).Sum();
