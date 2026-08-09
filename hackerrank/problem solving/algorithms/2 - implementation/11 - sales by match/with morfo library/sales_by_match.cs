// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

using Morfo.Collections;
using Morfo.IO;

Reader.SkipInputLn();
var socksToCounts = Counter.Of(Reader.ReadLn<int, int[]>());
Console.WriteLine(SockMerchant(socksToCounts));

// k: length of entries in socksToCounts
// T: O(k)
// S: O(1) extra space
int SockMerchant(Dictionary<int, int> socksToCounts) => socksToCounts.Values.Sum(x => x / 2);
