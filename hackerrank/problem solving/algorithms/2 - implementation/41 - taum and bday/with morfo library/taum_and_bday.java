// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

record Gifts(long nBlackGifts, long nWhiteGifts, long blackGiftCost, long whiteGiftCost,
             long costToConvertBetweenGifts) {
}

void main() {
    int n = Reader.read(Integer::parseInt);
    for (int i = 0; i < n; i++)
        IO.println(minCostOfBuyingGifts(readTestCase()));
}

Gifts readTestCase() {
    return new Gifts(
            Reader.read(Long::parseLong), Reader.read(Long::parseLong),
            Reader.read(Long::parseLong), Reader.read(Long::parseLong),
            Reader.read(Long::parseLong));
}

// T: O(1)
// S: O(1) extra space
long minCostOfBuyingGifts(Gifts x) {
    long blackCost = Math.min(x.blackGiftCost, x.whiteGiftCost + x.costToConvertBetweenGifts);
    long whiteCost = Math.min(x.whiteGiftCost, x.blackGiftCost + x.costToConvertBetweenGifts);
    return x.nBlackGifts * blackCost + x.nWhiteGifts * whiteCost;
}
