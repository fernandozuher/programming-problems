// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

Console.ReadLine();
Dictionary<int, int> socksToCounts = Counter(ReadNums());
Console.WriteLine(SockMerchant(socksToCounts));

int[] ReadNums() => Console.ReadLine()!.Split().Select(int.Parse).ToArray();

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(k) extra space
Dictionary<int, int> Counter(int[] arr)
{
    return arr.GroupBy(x => x).ToDictionary(g => g.Key, g => g.Count());
}

// k: length of entries in socksToCounts
// T: O(k)
// S: O(1) extra space
int SockMerchant(Dictionary<int, int> socksToCounts) => socksToCounts.Values.Sum(x => x / 2);
