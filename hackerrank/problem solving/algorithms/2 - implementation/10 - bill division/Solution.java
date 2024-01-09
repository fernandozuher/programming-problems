// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        int itemAnnaDidntConsume = scan.nextInt();
        scan.nextLine();

        List<Integer> costOfEachMeal = readIntArray();
        int brianChargedAnna = scan.nextInt();

        var obj = new BillDivision(costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna);
        printOutput(obj.brianOvercharged());
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }

        private static void printOutput(final int charged) {
            System.out.println(charged > 0 ? charged : "Bon Appetit");
        }
}

    class BillDivision {
        private List<Integer> costOfEachMeal;
        private int itemAnnaDidntConsume;
        private int brianChargedAnna;
        private int brianOverchargedAnna;

        BillDivision(List<Integer> costOfEachMeal, int itemAnnaDidntConsume, int brianChargedAnna) {
            this.costOfEachMeal = costOfEachMeal;
            this.itemAnnaDidntConsume = itemAnnaDidntConsume;
            this.brianChargedAnna = brianChargedAnna;
            brianOverchargedAnna = 0;

            bonAppetit();
        }

            private void bonAppetit() {
                int annaCost = calculateAnnaCost();
                calculateHowMuchBrianOverchargedAnna(annaCost);
            }

                private int calculateAnnaCost() {
                    int sum = costOfEachMeal.stream().mapToInt(Integer::intValue).sum();
                    int annaCost = (sum - costOfEachMeal.get(itemAnnaDidntConsume)) / 2;
                    return annaCost;
                }

                private void calculateHowMuchBrianOverchargedAnna(final int annaCost) {
                    if (annaCost != brianChargedAnna)
                        brianOverchargedAnna = brianChargedAnna - annaCost;
                }

        public int brianOvercharged() {
            return brianOverchargedAnna;
        }
    }
