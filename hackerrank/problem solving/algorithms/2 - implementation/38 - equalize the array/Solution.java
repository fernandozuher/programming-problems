// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isfullscreen=true

import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();

        var frequency = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; ++i)
            frequency.merge(scan.nextInt(), 1, Integer::sum);
        System.out.println(equalizeArray(frequency, n));
    }

        public static int equalizeArray(HashMap<Integer, Integer> map, int n) {
            int maximumQuantityOfEqualElement = Collections.max(map.values());
            int minimumNumberRequiredDeletions = n - maximumQuantityOfEqualElement;
            return minimumNumberRequiredDeletions;
        }
}
