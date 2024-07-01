// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true
// From Java 16

import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;

import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        var data = new Input();
        int n = scan.nextInt();
        data.itemAnnaDidntConsume = scan.nextInt();
        scan.nextLine();
        data.costOfEachMeal = readIntArray(n);
        data.brianChargedAnna = scan.nextInt();

        var obj = new BillDivision(data);
        obj.bonAppetit();
        printOutput(obj.brianOverchargedAnna());
    }

    private static List<Integer> readIntArray(final int n) {
        return Stream.of(new Integer[n]).map(_ -> scan.nextInt()).collect(toList());
    }

    private static void printOutput(final int charged) {
        System.out.println(charged > 0 ? charged : "Bon Appetit");
    }
}

    class Input {
        public int itemAnnaDidntConsume;
        public List<Integer> costOfEachMeal;
        public int brianChargedAnna;
    }

    class BillDivision {
        private final int itemAnnaDidntConsume;
        private final List<Integer> costOfEachMeal;
        private final int brianChargedAnna;
        private int brianOvercharged;

        BillDivision(Input data) {
            itemAnnaDidntConsume = data.itemAnnaDidntConsume;
            costOfEachMeal = data.costOfEachMeal;
            brianChargedAnna = data.brianChargedAnna;
            brianOvercharged = 0;
        }

        public void bonAppetit() {
            int annaCost = calculateAnnaCost();
            howMuchBrianOverchargedAnna(annaCost);
        }

            private int calculateAnnaCost() {
                int sum = costOfEachMeal.stream().mapToInt(Integer::intValue).sum();
                return (sum - costOfEachMeal.get(itemAnnaDidntConsume)) / 2;
            }

            private void howMuchBrianOverchargedAnna(final int annaCost) {
                if (annaCost != brianChargedAnna)
                    brianOvercharged = brianChargedAnna - annaCost;
            }

        public int brianOverchargedAnna() {
            return brianOvercharged;
        }
    }
