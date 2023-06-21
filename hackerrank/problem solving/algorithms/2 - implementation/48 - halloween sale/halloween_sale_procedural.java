// Source: https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

import java.util.Scanner;

public class HalloweenSale {
    private static Scanner _scanner = new Scanner(System.in);

    public static void main(String[] args) {
        final int gameDefaultPrice = _scanner.nextInt();
        final int discount = _scanner.nextInt();
        final int gameMinimumPrice = _scanner.nextInt();
        final int budget = _scanner.nextInt();

        System.out.println(_howManyGamesCanBeBought(gameDefaultPrice, discount, gameMinimumPrice, budget));
    }

        private static int _howManyGamesCanBeBought(int gameDefaultPrice, int discount, int gameMinimumPrice, int budget) {
            int gamesCanBeBoughtQuantity = 0;

            for (int currentGamePrice = gameDefaultPrice, currentBudget = budget - gameDefaultPrice; currentBudget >= 0;) {
                gamesCanBeBoughtQuantity++;
                currentGamePrice -= discount;
                currentBudget -= currentGamePrice >= gameMinimumPrice ? currentGamePrice : gameMinimumPrice;
            }

            return gamesCanBeBoughtQuantity;
        }
}
