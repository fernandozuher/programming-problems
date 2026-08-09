// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

using Morfo.IO;

int n = Reader.Read<int>();
for (int i = 0; i < n; i++)
    Console.WriteLine(MinCostOfBuyingGifts(ReadTestCase()));

Gifts ReadTestCase() => new Gifts(
    Reader.Read<long>(), Reader.Read<long>(),
    Reader.Read<long>(), Reader.Read<long>(),
    Reader.Read<long>());

// T: O(1)
// S: O(1) extra space
long MinCostOfBuyingGifts(Gifts x)
{
    long blackCost = Math.Min(x.BlackGiftCost, x.WhiteGiftCost + x.CostToConvertBetweenGifts);
    long whiteCost = Math.Min(x.WhiteGiftCost, x.BlackGiftCost + x.CostToConvertBetweenGifts);
    return x.NBlackGifts * blackCost + x.NWhiteGifts * whiteCost;
}

record struct Gifts(long NBlackGifts, long NWhiteGifts, long BlackGiftCost, long WhiteGiftCost, long CostToConvertBetweenGifts);
