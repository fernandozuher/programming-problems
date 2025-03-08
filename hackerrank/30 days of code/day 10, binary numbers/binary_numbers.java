// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int n = scan.nextInt();
            var binary = new IntToBinary(n);
            System.out.println(binary.sizeWidestRangeBitsOne());
        }
    }
}

class IntToBinary {
    private final String binary;
    private final int sizeWidestRangeBits1;

    IntToBinary(final int n) {
        this.binary = Integer.toBinaryString(n);
        this.sizeWidestRangeBits1 = findSizeWidestRangeBits1();
    }

    private int findSizeWidestRangeBits1() {
        int sizeWidestRange = 0;
        for (int i = 0; i < binary.length(); i++)
            if (binary.charAt(i) == '1') {
                int sizeRange = findSizeRangeBits1(i);
                sizeWidestRange = Math.max(sizeRange, sizeWidestRange);
                i += sizeRange;
            }
        return sizeWidestRange;
    }

    private int findSizeRangeBits1(int beginIndex) {
        int index = findBit0(beginIndex);
        int size = index == -1 ? binary.length() : index;
        size -= beginIndex;
        return size;
    }

    private int findBit0(int beginIndex) {
        return binary.indexOf('0', beginIndex);
    }

    public int sizeWidestRangeBitsOne() {
        return sizeWidestRangeBits1;
    }
}
