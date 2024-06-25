// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true
// From Java 21

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;

import static java.util.stream.Collectors.toList;

public class Main {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        final int n = 2;
        List<Integer> temp = readIntArray(n);
        List<Integer> setA = readIntArray(temp.getFirst());
        List<Integer> setB = readIntArray(temp.getLast());

        Collections.sort(setA);
        Collections.sort(setB);

        var obj = new BetweenTwoSets(setA, setB);
        obj.findFactors();
        System.out.print(obj.totalFactors());
    }

        public static List<Integer> readIntArray(final int n) {
            return Stream.of(new Integer[n]).map(_ -> scan.nextInt()).collect(toList());
        }
}

    class BetweenTwoSets {
        private final List<Integer> setA;
        private final List<Integer> setB;
        private final List<Integer> potentialFactors;
        private int factors;

        public BetweenTwoSets(List<Integer> setA, List<Integer> setB) {
            this.setA = setA;
            this.setB = setB;
            potentialFactors = new ArrayList<>();
            factors = 0;
        }

        public void findFactors() {
            findNumbersDivisibleBySetA();
            findFactorsOfSetB();
            countFactors();
        }

            private void findNumbersDivisibleBySetA() {
                for (int potentialFactor = setA.getLast(); potentialFactor <= setB.getFirst(); potentialFactor += setA.getLast()) {
                    boolean isARealPotentialFactor = true;

                    for (int x : setA)
                        if (potentialFactor % x != 0) {
                            isARealPotentialFactor = false;
                            break;
                        }

                    if (isARealPotentialFactor)
                        potentialFactors.add(potentialFactor);
                }
            }

            private void findFactorsOfSetB() {
                for (int x : setB)
                    for (int i = 0; i < potentialFactors.size(); ++i)
                        if (potentialFactors.get(i) != 0 && x % potentialFactors.get(i) != 0)
                            potentialFactors.set(i, 0);
            }

            private void countFactors() {
                factors = (int) potentialFactors.stream().filter(x -> x != 0).count();
            }

        public int totalFactors() {
            return factors;
        }
    }
