// Source: https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

using System;

public class Solution
{
    public static void Main()
    {
        int nTestCases = Convert.ToInt32(_ReadANumber());
        List<ulong> output = _InitializeEmptyArray(nTestCases);

        for (int i = 0; i < nTestCases; i++)
        {
            List<ulong> input = _ReadATestCase();
            TaumAndBday obj = new TaumAndBday(input);
            output[i] = obj.GetMinimumCostOfBuyingGifts();
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

        private static void _PrintArray(List<ulong> array)
        {
            array.ForEach(Console.WriteLine);
        }
}

    public class TaumAndBday
    {
        private ulong _NBlackGifts, _NWhiteGifts;
        private ulong _BlackGiftCost, _WhiteGiftCost;
        private ulong _CostToConvertBetweenGifts;

        private ulong _CostToConvertFromBlackToWhite, _CostToConvertFromWhiteToBlack;

        private ulong _MinimumCostOfBuyingGifts;

        public TaumAndBday(List<ulong> input) {
            _NBlackGifts = input.First();
            _NWhiteGifts = input[1];
            _BlackGiftCost = input[2];
            _WhiteGiftCost = input[3];
            _CostToConvertBetweenGifts = input.Last();

            _CostToConvertFromBlackToWhite = _BlackGiftCost + _CostToConvertBetweenGifts;
            _CostToConvertFromWhiteToBlack = _WhiteGiftCost + _CostToConvertBetweenGifts;

            _MinimumCostOfBuyingGifts = _CalculateMinimumCostOfBuyingGifts();
        }

            private ulong _CalculateMinimumCostOfBuyingGifts()
            {
                if (_AreOriginalCostsCheaperOrEqualThanConvertionBetweenGifts())
                    return _CalculateMinimumStandardCost();

                return _CalculateMinimumCostInConvertingGifts();
            }

                private bool _AreOriginalCostsCheaperOrEqualThanConvertionBetweenGifts()
                {
                    return _WhiteGiftCost <= _CostToConvertFromBlackToWhite && _BlackGiftCost <= _CostToConvertFromWhiteToBlack;
                }

                private ulong _CalculateMinimumStandardCost()
                {
                    return _NBlackGifts * _BlackGiftCost + _NWhiteGifts * _WhiteGiftCost;
                }

                private ulong _CalculateMinimumCostInConvertingGifts()
                {
                    ulong totalGifts = _NBlackGifts + _NWhiteGifts;

                    if (_WhiteGiftCost > _CostToConvertFromBlackToWhite)
                        return totalGifts * _BlackGiftCost + _NWhiteGifts * _CostToConvertBetweenGifts;

                    return totalGifts * _WhiteGiftCost + _NBlackGifts * _CostToConvertBetweenGifts;
                }

        public ulong GetMinimumCostOfBuyingGifts()
        {
            return _MinimumCostOfBuyingGifts;
        }
    }
