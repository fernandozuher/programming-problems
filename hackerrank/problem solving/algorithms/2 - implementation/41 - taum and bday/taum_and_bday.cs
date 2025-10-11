// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true


record struct Gifts(long nBlackGifts, long nWhiteGifts, long blackGiftCost,
                    long whiteGiftCost, long costToConvertBetweenGifts);

class Solution
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine()!);
        for (int i = 0; i < n; i++)
        {
            var testCase = ReadTestCase();
            Console.WriteLine(MinCostOfBuyingGifts(testCase));
        }
    }

    private static Gifts ReadTestCase()
    {
        var line1 = ReadNumbers();
        var line2 = ReadNumbers();
        return new Gifts(line1[0], line1[1], line2[0], line2[1], line2[2]);
    }

    private static long[] ReadNumbers()
    {
        return Console.ReadLine()!.Split().Select(long.Parse).ToArray();
    }

    private static long MinCostOfBuyingGifts(Gifts gifts)
    {
        long blackCost = Math.Min(gifts.blackGiftCost, gifts.whiteGiftCost + gifts.costToConvertBetweenGifts);
        long whiteCost = Math.Min(gifts.whiteGiftCost, gifts.blackGiftCost + gifts.costToConvertBetweenGifts);
        return gifts.nBlackGifts * blackCost + gifts.nWhiteGifts * whiteCost;
    }
}
