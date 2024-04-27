// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

using static System.Console;

namespace ProgrammingProblem
{
record struct Gifts(long nBlackGifts, long nWhiteGifts, long blackGiftCost,
                    long whiteGiftCost, long costToConvertBetweenGifts);

class Solution
{
    static void Main()
    {
        int n = int.Parse(ReadLine());
        var output = new List<long>(new long[n]).Select(x =>
        {
            var obj = new TaumAndBday(ReadTestCase());
            obj.CalculateMinimumCostOfBuyingGifts();
            return obj.MinimumCostOfBuyingGifts;
        }).ToList();

        output.ForEach(WriteLine);
    }

        static Gifts ReadTestCase()
        {
            var line1 = ReadLongArray();
            var line2 = ReadLongArray();
            return new Gifts(line1.First(), line1.Last(), line2.First(), line2[1], line2.Last());
        }

            static List<long> ReadLongArray()
            {
                return ReadLine().Split().Select(long.Parse).ToList();
            }
}

    class TaumAndBday
    {
        private Gifts _gifts;
        private long _costToConvertFromBlackToWhite, _costToConvertFromWhiteToBlack;
        private long _minimumCostOfBuyingGifts;

        public TaumAndBday(Gifts gifts) {
            _gifts = gifts;
            _costToConvertFromBlackToWhite = _gifts.blackGiftCost + _gifts.costToConvertBetweenGifts;
            _costToConvertFromWhiteToBlack = _gifts.whiteGiftCost + _gifts.costToConvertBetweenGifts;
            _minimumCostOfBuyingGifts = 0;
        }

        public void CalculateMinimumCostOfBuyingGifts()
        {
            _minimumCostOfBuyingGifts = _areOriginalCostsCheaperOrEqualThanConversionBetweenGifts() ?
                                        _calculateMinimumStandardCost() : _calculateMinimumCostInConvertingGifts();
        }

            private bool _areOriginalCostsCheaperOrEqualThanConversionBetweenGifts()
            {
                return _gifts.whiteGiftCost <= _costToConvertFromBlackToWhite
                       && _gifts.blackGiftCost <= _costToConvertFromWhiteToBlack;
            }

            private long _calculateMinimumStandardCost()
            {
                return _gifts.nBlackGifts * _gifts.blackGiftCost + _gifts.nWhiteGifts * _gifts.whiteGiftCost;
            }

            private long _calculateMinimumCostInConvertingGifts()
            {
                long totalGifts = _gifts.nBlackGifts + _gifts.nWhiteGifts;

                if (_gifts.whiteGiftCost > _costToConvertFromBlackToWhite)
                    return totalGifts * _gifts.blackGiftCost + _gifts.nWhiteGifts * _gifts.costToConvertBetweenGifts;

                return totalGifts * _gifts.whiteGiftCost + _gifts.nBlackGifts * _gifts.costToConvertBetweenGifts;
            }

        public long MinimumCostOfBuyingGifts
        {
            get => _minimumCostOfBuyingGifts;
        }
    }
}
