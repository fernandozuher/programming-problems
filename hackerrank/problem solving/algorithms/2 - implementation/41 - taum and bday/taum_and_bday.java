// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;
import java.util.stream.IntStream;

class Gifts {
    public long nBlackGifts;
    public long nWhiteGifts;
    public long blackGiftCost;
    public long whiteGiftCost;
    public long costToConvertBetweenGifts;
}

class Solution {
    void main() {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        IntStream.range(0, n).forEach(_ -> {
            Gifts testCase = readTestCase(scan);
            IO.println(minCostOfBuyingGifts(testCase));
        });
    }

    private static Gifts readTestCase(Scanner scan) {
        var x = new Gifts();
        x.nBlackGifts = scan.nextLong();
        x.nWhiteGifts = scan.nextLong();
        x.blackGiftCost = scan.nextLong();
        x.whiteGiftCost = scan.nextLong();
        x.costToConvertBetweenGifts = scan.nextLong();
        return x;
    }

    private static long minCostOfBuyingGifts(Gifts gifts) {
        long blackCost = Math.min(gifts.blackGiftCost, gifts.whiteGiftCost + gifts.costToConvertBetweenGifts);
        long whiteCost = Math.min(gifts.whiteGiftCost, gifts.blackGiftCost + gifts.costToConvertBetweenGifts);
        return gifts.nBlackGifts * blackCost + gifts.nWhiteGifts * whiteCost;
    }
}
