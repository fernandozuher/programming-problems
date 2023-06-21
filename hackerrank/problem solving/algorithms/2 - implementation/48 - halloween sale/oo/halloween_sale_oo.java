// Source: https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    private static Scanner _scanner = new Scanner(System.in);

    public static void main(String[] args) {
        final int gameDefaultPrice = _scanner.nextInt();
        final int discount = _scanner.nextInt();
        final int gameMinimumPrice = _scanner.nextInt();
        final int budget = _scanner.nextInt();

        final HalloweenSale obj = new HalloweenSale(gameDefaultPrice, discount, gameMinimumPrice, budget);
        System.out.println(obj.getGamesCanBeBoughtQuantity());
    }
}

    class HalloweenSale {
        private int _gameDefaultPrice, _discount, _gameMinimumPrice, _budget;
        private int _gamesCanBeBoughtQuantity = 0;

        public HalloweenSale(int gameDefaultPrice, int discount, int gameMinimumPrice, int budget) {
            _gameDefaultPrice = gameDefaultPrice;
            _discount = discount;
            _gameMinimumPrice = gameMinimumPrice;
            _budget = budget;

            _calculateHowManyGamesCanBeBought();
        }

            private void _calculateHowManyGamesCanBeBought() {
                for (int currentGamePrice = _gameDefaultPrice, currentBudget = _budget - _gameDefaultPrice; currentBudget >= 0;) {
                    _gamesCanBeBoughtQuantity++;
                    currentGamePrice -= _discount;
                    currentBudget -= currentGamePrice >= _gameMinimumPrice ? currentGamePrice : _gameMinimumPrice;
                }
            }

        public int getGamesCanBeBoughtQuantity() {
            return _gamesCanBeBoughtQuantity;
        }
    }
