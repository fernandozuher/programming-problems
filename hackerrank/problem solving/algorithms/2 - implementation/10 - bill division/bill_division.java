// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true
// Java 16

import java.util.*;
import java.util.stream.IntStream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            var data = readInput(scan);
            printOutput(new BillDivision(data).bonAppetit());
        }
    }

    private static Input readInput(Scanner scan) {
        int n = scan.nextInt();
        int itemNotEaten = scan.nextInt();
        scan.nextLine();
        return new Input(itemNotEaten, readNumbers(scan, n), scan.nextInt());
    }

    private static int[] readNumbers(Scanner scan, int n) {
        return IntStream.range(0, n).map(_ -> scan.nextInt()).toArray();
    }

    private static void printOutput(int charged) {
        System.out.println(charged > 0 ? charged : "Bon Appetit");
    }
}

record Input(int itemNotEaten, int[] mealCosts, int amountCharged) {
}

class BillDivision {
    private final int itemNotEaten;
    private final int[] mealCosts;
    private final int amountCharged;

    BillDivision(Input data) {
        itemNotEaten = data.itemNotEaten();
        mealCosts = data.mealCosts();
        amountCharged = data.amountCharged();
    }

    public int bonAppetit() {
        return amountCharged - computeActualShare();
    }

    private int computeActualShare() {
        int totalCost = Arrays.stream(mealCosts).sum();
        int totalSharedCost = totalCost - mealCosts[itemNotEaten];
        return totalSharedCost / 2;
    }
}
