// Source: https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        readIntArray();
        List<Integer> setA = readIntArray();
        List<Integer> setB = readIntArray();

        Collections.sort(setA);
        Collections.sort(setB);

        var result = new BetweenTwoSets(setA, setB);
        System.out.println(result.totalFactors());
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }
}

    class BetweenTwoSets {
        private List<Integer> setA, setB, potentialFactors;
        private int factors;

        public BetweenTwoSets(List<Integer> setA, List<Integer> setB) {
            this.setA = new ArrayList<Integer>(setA);
            this.setB = new ArrayList<Integer>(setB);
            potentialFactors = new ArrayList<Integer>();
            factors = 0;

            findFactors();
        }

        private void findFactors() {
            findNumbersDivisibleBySetA();
            findFactorsOfSetB();
            countFactors();
        }

            private void findNumbersDivisibleBySetA() {
                int lastElementOfSetA = setA.get(setA.size() - 1);

                for (int potentialFactor = lastElementOfSetA; potentialFactor <= setB.get(0); potentialFactor += lastElementOfSetA) {
                    boolean isARealPotentialFactor = true;

                    for (int elementA : setA)
                        if (potentialFactor % elementA != 0) {
                            isARealPotentialFactor = false;
                            break;
                        }

                    if (isARealPotentialFactor)
                        potentialFactors.add(potentialFactor);
                }
            }

            private void findFactorsOfSetB() {
                for (int elementB : setB)
                    for (int i = 0; i < potentialFactors.size(); i++)
                        if (potentialFactors.get(i) != 0 && elementB % potentialFactors.get(i) != 0)
                            potentialFactors.set(i, 0);
            }

            private void countFactors() {
                factors = potentialFactors.stream().reduce(0, (sum, item) -> item != 0 ? ++sum : sum);
            }

        public int totalFactors() {
            return factors;
        }
    }
