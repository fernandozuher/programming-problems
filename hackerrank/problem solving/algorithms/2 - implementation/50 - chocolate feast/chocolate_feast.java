// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true
// Java 25

import java.lang.*;
import java.util.*;

class Solution {
    void main() {
        var scan = new Scanner(System.in);
        for (int i = 0, n = scan.nextInt(); i < n; i++) {
            int money = scan.nextInt();
            int cost = scan.nextInt();
            int wrappersNeeded = scan.nextInt();
            IO.println(howManyChocolatesCanBeEaten(money, cost, wrappersNeeded));
        }
    }

    private static int howManyChocolatesCanBeEaten(int money, int cost, int wrappersNeeded) {
        int chocolates = money / cost;

        for (int wrappers = chocolates; wrappers >= wrappersNeeded; ) {
            int freeChocolates = wrappers / wrappersNeeded;
            wrappers = wrappers % wrappersNeeded + freeChocolates;
            chocolates += freeChocolates;
        }

        return chocolates;
    }
}
