// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

Console.ReadLine();
Dictionary<int, int> sockCounts = Counter();
Console.WriteLine(SockMerchant(sockCounts));

Dictionary<int, int> Counter()
{
    var counter = new Dictionary<int, int>();
    foreach (var x in Console.ReadLine()!.Split().Select(int.Parse))
    {
        counter.TryGetValue(x, out int count);
        counter[x] = ++count;
    }
    return counter;
}

// n: quantity of entries in sockCounts
// T: O(n)
// S: O(1) extra space
int SockMerchant(Dictionary<int, int> sockCounts) => sockCounts.Values.Sum(count => count / 2);
