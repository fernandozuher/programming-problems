// Source: https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

import java.util.Scanner;
import java.util.List;
import java.util.Arrays;

public class TaumAndBday {
    private static Scanner _scanner;

    public static void main(String[] args) {
        _scanner = new Scanner(System.in);

        final int N_TEST_CASES = (int) _readANumber();
        List<Long> output = _initializeEmptyArray(N_TEST_CASES);

        for (int i = 0; i < N_TEST_CASES; i++) {
            final List<Long> INPUT = _readATestCase();
            output.set(i, _calculateMinimumCostOfBuyingGifts(INPUT));
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

        private static long _calculateMinimumCostOfBuyingGifts(List<Long> input) {
            if (_areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts(input))
                return _calculateMinimumStandardCost(input);
            return _calculateMinimumCostInConvertingGifts(input);
        }

            private static boolean _areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts(List<Long> input) {
                final long BLACK_GIFT_COST = input.get(2);
                final long WHITE_GIFT_COST = input.get(3);
                final long COST_TO_CONVERT_BETWEEN_GIFTS = input.get(4);

                final long COST_TO_CONVERT_FROM_BLACK_TO_WHITE = BLACK_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS;
                final long COST_TO_CONVERT_FROM_WHITE_TO_BLACK = WHITE_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS;

                return WHITE_GIFT_COST <= COST_TO_CONVERT_FROM_BLACK_TO_WHITE && BLACK_GIFT_COST <= COST_TO_CONVERT_FROM_WHITE_TO_BLACK;
            }

            private static long _calculateMinimumStandardCost(List<Long> input) {
                final long N_BLACK_GIFTS = input.get(0);
                final long N_WHITE_GIFTS = input.get(1);
                final long BLACK_GIFT_COST = input.get(2);
                final long WHITE_GIFT_COST = input.get(3);

                return N_BLACK_GIFTS * BLACK_GIFT_COST + N_WHITE_GIFTS * WHITE_GIFT_COST;
            }

            private static long _calculateMinimumCostInConvertingGifts(List<Long> input) {
                final long N_BLACK_GIFTS = input.get(0);
                final long N_WHITE_GIFTS = input.get(1);
                final long BLACK_GIFT_COST = input.get(2);
                final long WHITE_GIFT_COST = input.get(3);
                final long COST_TO_CONVERT_BETWEEN_GIFTS = input.get(4);

                final long COST_TO_CONVERT_FROM_BLACK_TO_WHITE = BLACK_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS;
                final long TOTAL_GIFTS = N_BLACK_GIFTS + N_WHITE_GIFTS;

                long minimumCostOfBuyingGifts;

                if (WHITE_GIFT_COST > COST_TO_CONVERT_FROM_BLACK_TO_WHITE)
                    minimumCostOfBuyingGifts = TOTAL_GIFTS * BLACK_GIFT_COST + N_WHITE_GIFTS * COST_TO_CONVERT_BETWEEN_GIFTS;
                else
                    minimumCostOfBuyingGifts = TOTAL_GIFTS * WHITE_GIFT_COST + N_BLACK_GIFTS * COST_TO_CONVERT_BETWEEN_GIFTS;

                return minimumCostOfBuyingGifts;
            }

        private static void _printArray(List<Long> array) {
            array.forEach(System.out::println);
        }
}