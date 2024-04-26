// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Gifts {
    public long nBlackGifts;
    public long nWhiteGifts;
    public long blackGiftCost;
    public long whiteGiftCost;
    public long costToConvertBetweenGifts;
}

public class Main {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        // _ -> from Java 21
        List<Long> output = Arrays.stream(new Long[n]).map(_ -> {
            var obj = new TaumAndBday(readTestCase());
            obj.calculateMinimumCostOfBuyingGifts();
            return obj.minimumCostOfBuyingGifts();
        }).toList(); // Stream.toList from Java 16

        output.forEach(System.out::println);
    }

        private static Gifts readTestCase() {
            var x = new Gifts();
            x.nBlackGifts = scan.nextLong();
            x.nWhiteGifts = scan.nextLong();
            x.blackGiftCost = scan.nextLong();
            x.whiteGiftCost = scan.nextLong();
            x.costToConvertBetweenGifts = scan.nextLong();
            return x;
        }
}

    class TaumAndBday {
        private final Gifts gifts;
        private final long costToConvertFromBlackToWhite;
        private final long costToConvertFromWhiteToBlack;
        private final long minCostOfBuyingGifts;

        public TaumAndBday(final Gifts gifts) {
            this.gifts = gifts;
            costToConvertFromBlackToWhite = gifts.blackGiftCost + gifts.costToConvertBetweenGifts;
            costToConvertFromWhiteToBlack = gifts.whiteGiftCost + gifts.costToConvertBetweenGifts;
            minCostOfBuyingGifts = calculateMinimumCostOfBuyingGifts();
        }

        public long calculateMinimumCostOfBuyingGifts() {
            if (areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts()) return calculateMinimumStandardCost();
            return calculateMinimumCostInConvertingGifts();
        }

            private boolean areOriginalCostsCheaperOrEqualThanConvertionBetweenGifts() {
                return gifts.whiteGiftCost <= costToConvertFromBlackToWhite && gifts.blackGiftCost <= costToConvertFromWhiteToBlack;
            }

            private long calculateMinimumStandardCost() {
                return gifts.nBlackGifts * gifts.blackGiftCost + gifts.nWhiteGifts * gifts.whiteGiftCost;
            }

            private long calculateMinimumCostInConvertingGifts() {
                long totalGifts = gifts.nBlackGifts + gifts.nWhiteGifts;

                if (gifts.whiteGiftCost > costToConvertFromBlackToWhite)
                    return totalGifts * gifts.blackGiftCost + gifts.nWhiteGifts * gifts.costToConvertBetweenGifts;

                return totalGifts * gifts.whiteGiftCost + gifts.nBlackGifts * gifts.costToConvertBetweenGifts;
            }

        public long minimumCostOfBuyingGifts() {
            return minCostOfBuyingGifts;
        }
    }
