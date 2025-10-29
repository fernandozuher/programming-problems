// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

Console.ReadLine();
Dictionary<int, int> sockCounts = ReadNumbersIntoMap();
Console.WriteLine(SockMerchant(sockCounts));

Dictionary<int, int> ReadNumbersIntoMap()
{
    var counter = new Dictionary<int, int>();
    foreach (var x in Console.ReadLine()!.Split().Select(int.Parse))
    {
        counter.TryGetValue(x, out int count);
        counter[x] = ++count;
    }
    return counter;
}

int SockMerchant(Dictionary<int, int> sockCounts) => sockCounts.Values.Sum(count => count / 2);
