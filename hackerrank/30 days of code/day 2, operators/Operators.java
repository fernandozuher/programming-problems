// https://www.hackerrank.com/challenges/30-operators/problem?isFullScreen=true

import java.util.Scanner;

public class Operators {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double mealCost = scanner.nextDouble();
        int tipPercent = scanner.nextInt();
        int taxPercent = scanner.nextInt();

        solve(mealCost, tipPercent, taxPercent);
    }

        private static void solve(final double mealCost, final int tipPercent, final int taxPercent) {
            final double totalCost = mealCost + mealCost * tipPercent / 100 + mealCost * taxPercent / 100;
            System.out.format("%.0f", totalCost);
        }
}
