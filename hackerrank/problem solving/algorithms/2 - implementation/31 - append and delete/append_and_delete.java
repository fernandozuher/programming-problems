// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            String initialString = scan.nextLine();
            String finalString = scan.nextLine();
            int nOperations = scan.nextInt();
            System.out.println(appendAndDelete(initialString, finalString, nOperations) ? "Yes" : "No");
        }
    }

    private static boolean appendAndDelete(String s1, String s2, int nOps) {
        int prefixLen = commonPrefixLength(s1, s2);
        int totalOpsNeeded = (s1.length() - prefixLen) + (s2.length() - prefixLen);
        boolean canRemoveAll = nOps >= s1.length() + s2.length();
        return canRemoveAll || (nOps >= totalOpsNeeded && (nOps - totalOpsNeeded) % 2 == 0);
    }

    private static int commonPrefixLength(String s1, String s2) {
        int minLen = Math.min(s1.length(), s2.length());
        for (int i = 0; i < minLen; i++)
            if (s1.charAt(i) != s2.charAt(i)) return i;
        return minLen;
    }
}
