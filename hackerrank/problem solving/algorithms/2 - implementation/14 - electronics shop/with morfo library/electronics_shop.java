// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    int budget = Reader.readLnInts()[0];
    int[] keyboards = preprocessInput(Reader.readLnInts());
    int[] usbDrives = preprocessInput(Reader.readLnInts());
    IO.println(calcMoneySpent(keyboards, usbDrives, budget));
}

// n: length of arr
// k: length of arr after deduplication
// k <= n
// T: O(n + k log k)
// S: O(k) extra space
int[] preprocessInput(int[] arr) {
    return IntStream.of(arr).distinct().sorted().toArray();
}

// n1: length of keyboards
// n2: length of usbDrives
// T: O(n1 + n2)
// S: O(1) extra space
int calcMoneySpent(int[] keyboards, int[] usbDrives, int budget) {
    if (keyboards[0] >= budget || usbDrives[0] >= budget) return -1;

    int maxSpent = -1;
    for (int idxK = 0, idxUD = usbDrives.length - 1; idxK < keyboards.length && idxUD >= 0; ) {
        if (keyboards[idxK] >= budget) break;

        int currentSum = keyboards[idxK] + usbDrives[idxUD];
        if (currentSum == budget) return budget;
        if (currentSum > budget) idxUD--;
        else {
            maxSpent = Math.max(maxSpent, currentSum);
            idxK++;
        }
    }

    return maxSpent;
}
