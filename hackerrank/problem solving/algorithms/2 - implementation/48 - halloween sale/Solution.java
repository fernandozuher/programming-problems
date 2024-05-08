// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int defaultPriceGame = scan.nextInt();
        int discount = scan.nextInt();
        int minimumPriceGame = scan.nextInt();
        int budget = scan.nextInt();
        System.out.println(howManyGamesCanBeBought(defaultPriceGame, discount, minimumPriceGame, budget));
    }

        public static int howManyGamesCanBeBought(int defaultPriceGame, int discount, int minimumPriceGame, int budget) {
            int gamesCanBeBoughtQuantity = 0;

            for (int currentPriceGame = defaultPriceGame, currentBudget = budget - defaultPriceGame; currentBudget >= 0; ) {
                ++gamesCanBeBoughtQuantity;
                currentPriceGame -= discount;
                currentBudget -= Math.max(currentPriceGame, minimumPriceGame);
            }

            return gamesCanBeBoughtQuantity;
        }
}
