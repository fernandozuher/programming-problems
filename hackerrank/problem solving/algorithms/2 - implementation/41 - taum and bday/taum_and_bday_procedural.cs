// Source: https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

using System;

public class TaumAndBday
{
    public static void Main()
    {
        int nTestCases = Convert.ToInt32(_ReadANumber());
        List<ulong> output = _InitializeEmptyArray(nTestCases);

        for (int i = 0; i < nTestCases; i++)
        {
            List<ulong> input = _ReadATestCase();
            output[i] = _CalculateMinimumCostOfBuyingGifts(input);
        }

        _PrintArray(output);
    }

        private static ulong _ReadANumber()
        {
            return ulong.Parse(Console.ReadLine());
        }

        private static List<ulong> _InitializeEmptyArray(int size)
        {
            return new List<ulong>(new ulong[size]);
        }

        private static List<ulong> _ReadATestCase()
        {
            List<ulong> array = Console.ReadLine().Split().Select(ulong.Parse).ToList();
            ulong nBlackGifts = array.First();
            ulong nWhiteGifts = array.Last();

            array = Console.ReadLine().Split().Select(ulong.Parse).ToList();
            ulong blackGiftCost = array.First();
            ulong whiteGiftCost = array[1];
            ulong costToConvertBetweenGifts = array.Last();

            return new List<ulong> {nBlackGifts, nWhiteGifts, blackGiftCost, whiteGiftCost, costToConvertBetweenGifts};
        }

        private static ulong _CalculateMinimumCostOfBuyingGifts(List<ulong> input)
        {
            if (_AreOriginalCostsCheaperOrEqualThanConvertionBetweenGifts(input))
                return _CalculateMinimumStandardCost(input);
            return _CalculateMinimumCostInConvertingGifts(input);
        }

            private static bool _AreOriginalCostsCheaperOrEqualThanConvertionBetweenGifts(List<ulong> input)
            {
                ulong blackGiftCost = input[2];
                ulong whiteGiftCost = input[3];
                ulong costToConvertBetweenGifts = input[4];

                ulong costToConvertFromBlackToWhite = blackGiftCost + costToConvertBetweenGifts;
                ulong costToConvertFromWhiteToBlack = whiteGiftCost + costToConvertBetweenGifts;

                return whiteGiftCost <= costToConvertFromBlackToWhite && blackGiftCost <= costToConvertFromWhiteToBlack;
            }

            private static ulong _CalculateMinimumStandardCost(List<ulong> input)
            {
                ulong nBlackGifts = input.First();
                ulong nWhiteGifts = input[1];
                ulong blackGiftCost = input[2];
                ulong whiteGiftCost = input[3];

                return nBlackGifts * blackGiftCost + nWhiteGifts * whiteGiftCost;
            }

            private static ulong _CalculateMinimumCostInConvertingGifts(List<ulong> input)
            {
                ulong nBlackGifts = input.First();
                ulong nWhiteGifts = input[1];
                ulong blackGiftCost = input[2];
                ulong whiteGiftCost = input[3];
                ulong costToConvertBetweenGifts = input[4];

                ulong costToConvertFromBlackToWhite = blackGiftCost + costToConvertBetweenGifts;
                ulong totalGifts = nBlackGifts + nWhiteGifts;
                ulong minimumCostOfBuyingGifts;

                if (whiteGiftCost > costToConvertFromBlackToWhite)
                    minimumCostOfBuyingGifts = totalGifts * blackGiftCost + nWhiteGifts * costToConvertBetweenGifts;
                else
                    minimumCostOfBuyingGifts = totalGifts * whiteGiftCost + nBlackGifts * costToConvertBetweenGifts;

                return minimumCostOfBuyingGifts;
            }

        private static void _PrintArray(List<ulong> array)
        {
            array.ForEach(Console.WriteLine);
        }
}