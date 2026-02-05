// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true
// Java 25

record Gifts(long nBlackGifts, long nWhiteGifts, long blackGiftCost, long whiteGiftCost,
             long costToConvertBetweenGifts) {
}

void main() {
    int n = (int) readNumbers()[0];
    for (int i = 0; i < n; i++)
        IO.println(minCostOfBuyingGifts(readTestCase()));
}

long[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToLong(Long::parseLong).toArray();
}

Gifts readTestCase() {
    var arr1 = readNumbers();
    var arr2 = readNumbers();
    return new Gifts(arr1[0], arr1[1], arr2[0], arr2[1], arr2[2]);
}

// T: O(1)
// S: O(1) extra space
long minCostOfBuyingGifts(Gifts x) {
    long blackCost = Math.min(x.blackGiftCost, x.whiteGiftCost + x.costToConvertBetweenGifts);
    long whiteCost = Math.min(x.whiteGiftCost, x.blackGiftCost + x.costToConvertBetweenGifts);
    return x.nBlackGifts * blackCost + x.nWhiteGifts * whiteCost;
}
