// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.Scanner;

class Solution {
    void main() {
        var scan = new Scanner(System.in);
        int price = scan.nextInt();
        int discount = scan.nextInt();
        int minPrice = scan.nextInt();
        int budget = scan.nextInt();
        IO.println(howManyGamesCanBeBought(price, discount, minPrice, budget));
    }

    private static int howManyGamesCanBeBought(int price, int discount, int minPrice, int budget) {
        int count = 0;
        while (budget >= price) {
            count++;
            budget -= price;
            price = Math.max(price - discount, minPrice);
        }
        return count;
    }
}
