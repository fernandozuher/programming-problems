// Source: https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;

public class Solution {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int N_TEST_CASES = (int) _readANumber();
        List<Long> output = _initializeEmptyArray(N_TEST_CASES);

        for (int i = 0; i < N_TEST_CASES; i++) {
            final List<Long> INPUT = _readATestCase();
            final TaumAndBday OBJ = new TaumAndBday(INPUT);
            output.set(i, OBJ.getMinimumCostOfBuyingGifts());
        }

        _printArray(output);
    }

        private static long _readANumber() {
            return _scanner.nextInt();
        }

        private static List<Long> _initializeEmptyArray(int size) {
            return Arrays.asList(new Long[size]);
        }

        private static List<Long> _readATestCase() {
            final long N_BLACK_GIFTS = _readANumber();
            final long N_WHITE_GIFTS = _readANumber();
            final long BLACK_GIFT_COST = _readANumber();
            final long WHITE_GIFT_COST = _readANumber();
            final long COST_TO_CONVERT_BETWEEN_GIFTS = _readANumber();

            return Arrays.asList(N_BLACK_GIFTS, N_WHITE_GIFTS, BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS);
        }

        private static void _printArray(List<Long> array) {
            array.forEach(System.out::println);
        }
}

    class TaumAndBday {
        private long _nBlackGifts, _nWhiteGifts;
        private long _blackGiftCost, _whiteGiftCost;
        private long _costToConvertBetweenGifts;

        private long _costToConvertFromBlackToWhite, _costToConvertFromWhiteToBlack;

        private long _minimumCostOfBuyingGifts;

        public TaumAndBday(List<Long> input) {
            _nBlackGifts = input.get(0);
            _nWhiteGifts = input.get(1);
            _blackGiftCost = input.get(2);
            _whiteGiftCost = input.get(3);
            _costToConvertBetweenGifts = input.get(4);

            _costToConvertFromBlackToWhite = _blackGiftCost + _costToConvertBetweenGifts;
            _costToConvertFromWhiteToBlack = _whiteGiftCost + _costToConvertBetweenGifts;

            _minimumCostOfBuyingGifts = _calculateMinimumCostOfBuyingGifts();
        }

            private long _calculateMinimumCostOfBuyingGifts() {
                if (_areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts())
                    return _calculateMinimumStandardCost();

                return _calculateMinimumCostInConvertingGifts();
            }

                private boolean _areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts() {
                    return _whiteGiftCost <= _costToConvertFromBlackToWhite && _blackGiftCost <= _costToConvertFromWhiteToBlack;
                }

                private long _calculateMinimumStandardCost() {
                    return _nBlackGifts * _blackGiftCost + _nWhiteGifts * _whiteGiftCost;
                }

                private long _calculateMinimumCostInConvertingGifts() {
                    final long TOTAL_GIFTS = _nBlackGifts + _nWhiteGifts;

                    if (_whiteGiftCost > _costToConvertFromBlackToWhite)
                        return TOTAL_GIFTS * _blackGiftCost + _nWhiteGifts * _costToConvertBetweenGifts;

                    return TOTAL_GIFTS * _whiteGiftCost + _nBlackGifts * _costToConvertBetweenGifts;
                }

        public long getMinimumCostOfBuyingGifts() {
            return _minimumCostOfBuyingGifts;
        }
    }
