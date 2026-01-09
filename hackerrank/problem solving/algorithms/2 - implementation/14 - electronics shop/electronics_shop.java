// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true
// Java 25

void main() {
    int budget = readNumbers()[0];
    int[] keyboards = preprocessInput(readNumbers());
    int[] usbDrives = preprocessInput(readNumbers());
    IO.println(calculateMoneySpent(keyboards, usbDrives, budget));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int[] preprocessInput(int[] arr) {
    return IntStream.of(arr).distinct().sorted().toArray();
}

// n: length of array keyboards
// m: length of array usbDrives
// T: O(n + m)
// S: O(1) extra space
int calculateMoneySpent(int[] keyboards, int[] usbDrives, int budget) {
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
