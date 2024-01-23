// https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int budget = scan.nextInt();
        int nKeyboardCosts = scan.nextInt();
        int nUsbDriveCosts = scan.nextInt();
        scan.nextLine();

        List<Integer> keyboardCosts = readIntArray();
        List<Integer> usbDriveCosts = readIntArray();

        Collections.sort(keyboardCosts);
        Collections.sort(usbDriveCosts);

        ElectronicsShop obj = new ElectronicsShop(keyboardCosts, usbDriveCosts, budget);
        System.out.println(obj.moneyThatCanBeSpent());
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }
}

    class ElectronicsShop {
        private List<Integer> keyboardCosts;
        private List<Integer> usbDriveCosts;
        private int budget;
        private int moneyCanBeSpent;

        public ElectronicsShop(final List<Integer> keyboardCosts, final List<Integer> usbDriveCosts, final int budget) {
            this.keyboardCosts = keyboardCosts;
            this.usbDriveCosts = usbDriveCosts;
            this.budget = budget;
            moneyCanBeSpent = 0;
            calculateMoneySpent();
        }

            private void calculateMoneySpent() {
                for (int i = 0, nKeyboardCosts = keyboardCosts.size(); i < nKeyboardCosts; ++i) {

                    if (isNextCostEqualToCurrentOne(keyboardCosts, i))
                        continue;

                    for (int j = 0, nUsbDriveCosts = usbDriveCosts.size(); j < nUsbDriveCosts; ++j) {

                        if (isNextCostEqualToCurrentOne(usbDriveCosts, j))
                            continue;

                        int sum = keyboardCosts.get(i) + usbDriveCosts.get(j);

                        if (isSumAffordableByBudget(sum))
                            moneyCanBeSpent = updateCost(sum);
                        else
                            break;
                    }
                }

                moneyCanBeSpent = moneyCanBeSpent > 0 ? moneyCanBeSpent : -1;
            }

                private boolean isNextCostEqualToCurrentOne(final List<Integer> deviceCosts, final int i) {
                    return i < deviceCosts.size() - 1 && deviceCosts.get(i) == deviceCosts.get(i + 1);
                }

                private boolean isSumAffordableByBudget(final int sum) {
                    return sum <= budget;
                }

                private int updateCost(final int sum) {
                    return Math.max(sum, moneyCanBeSpent);
                }

        public int moneyThatCanBeSpent() {
            return moneyCanBeSpent;
        }
    }
