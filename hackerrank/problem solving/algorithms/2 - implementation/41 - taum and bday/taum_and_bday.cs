// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

int n = int.Parse(Console.ReadLine()!);
for (int i = 0; i < n; i++)
    Console.WriteLine(MinCostOfBuyingGifts(ReadTestCase()));

Gifts ReadTestCase()
{
    var arr1 = ReadNumbers();
    var arr2 = ReadNumbers();
    return new Gifts(arr1[0], arr1[1], arr2[0], arr2[1], arr2[2]);
}

long[] ReadNumbers() => Console.ReadLine()!.Split().Select(long.Parse).ToArray();

// T: O(1)
// S: O(1) extra space
long MinCostOfBuyingGifts(Gifts x)
{
    long blackCost = Math.Min(x.BlackGiftCost, x.WhiteGiftCost + x.CostToConvertBetweenGifts);
    long whiteCost = Math.Min(x.WhiteGiftCost, x.BlackGiftCost + x.CostToConvertBetweenGifts);
    return x.NBlackGifts * blackCost + x.NWhiteGifts * whiteCost;
}

record struct Gifts(long NBlackGifts, long NWhiteGifts, long BlackGiftCost, long WhiteGiftCost, long CostToConvertBetweenGifts);
