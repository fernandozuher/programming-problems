// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            var binary = new IntToBinary(n);
            System.out.println(binary.maxConsecutiveOnesFromBinary());
        }
    }
}

class IntToBinary {
    private final String binary;
    private int maxConsecutiveOnes = 0;

    IntToBinary(final int n) {
        this.binary = Integer.toBinaryString(n);
        this.maxConsecutiveOnes = findMaxConsecutiveOnesFromBinary();
    }

    private int findMaxConsecutiveOnesFromBinary() {
        int max1Bits = 0;
        for (int i = 0; i < binary.length(); i++)
            if (binary.charAt(i) == '1') {
                int nBits = sizeOfNextRangeOfBits1(i);
                max1Bits = Math.max(nBits, max1Bits);
                i += nBits;
            }
        return max1Bits;
    }

    private int sizeOfNextRangeOfBits1(int beginIndex) {
        int nextAfterLastIndex = findNextAfterLastIndexOfConsecutive1s(beginIndex);
        return nextAfterLastIndex - beginIndex;
    }

    private int findNextAfterLastIndexOfConsecutive1s(int beginIndex) {
        int nextAfterLastIndex = binary.indexOf('0', beginIndex);
        return nextAfterLastIndex == -1 ? binary.length() : nextAfterLastIndex;
    }

    public int maxConsecutiveOnesFromBinary() {
        return maxConsecutiveOnes;
    }
}
