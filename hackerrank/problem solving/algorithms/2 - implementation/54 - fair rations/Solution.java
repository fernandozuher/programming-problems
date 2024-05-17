// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scan.nextInt();
        int minLoaves = findMinLoavesToSatisfyRules(n);
        if (minLoaves == -1) System.out.println("NO");
        else System.out.println(minLoaves);
    }

        public static int findMinLoavesToSatisfyRules(int n) {
            int minLoavesToSatisfyRules = 0;
            int loaves = scan.nextInt();

            while (--n > 0) {
                if (isOdd(loaves)) {
                    loaves = scan.nextInt() + 1;
                    minLoavesToSatisfyRules += 2;
                } else loaves = scan.nextInt();
            }

            return isOdd(loaves) ? -1 : minLoavesToSatisfyRules;
        }

            public static boolean isOdd(int n) {
                return (n & 1) == 1;
            }
}
