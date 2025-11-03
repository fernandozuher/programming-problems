// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.*;
import java.util.stream.IntStream;

void main() {
    int budget = readNumbers()[0];
    int[] keyboards = IntStream.of(readNumbers()).distinct().toArray();
    int[] usbDrives = IntStream.of(readNumbers()).distinct().toArray();
    Arrays.sort(keyboards);
    Arrays.sort(usbDrives);
    IO.println(calculateMoneySpent(keyboards, usbDrives, budget));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int calculateMoneySpent(int[] keyboards, int[] usbDrives, int budget) {
    int maxSpent = -1, i = 0, j = usbDrives.length - 1;

    while (i < keyboards.length && j >= 0) {
        if (keyboards[i] >= budget) break;

        int sum = keyboards[i] + usbDrives[j];
        if (sum > budget) j--;
        else if (sum == budget) return budget;
        else {
            if (sum > maxSpent) maxSpent = sum;
            i++;
        }
    }

    return maxSpent;
}
