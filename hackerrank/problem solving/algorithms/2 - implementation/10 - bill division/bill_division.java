// Source: https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        final List<Integer> input1 = readLineAsListInteger(bufferedReader);
        final int itemAnnaDidntConsume = input1.get(1);
        
        final List<Integer> costOfEachMeal = readLineAsListInteger(bufferedReader);
        final List<Integer> brianChargedAnna = readLineAsListInteger(bufferedReader);

        Result result = new Result(costOfEachMeal, itemAnnaDidntConsume, brianChargedAnna.get(0));
    }

        private static List<Integer> readLineAsListInteger(BufferedReader bufferedReader) {
            try {
                var numbers = Stream.of(bufferedReader.readLine().split(" "))
                              .map(Integer::parseInt)
                              .collect(toList());

                return numbers;
            } catch (Exception e) {
                System.out.println("Exception caught during reading");
            }
            return null;
        }
}

    class Result {
        private List<Integer> _costOfEachMeal;
        private int _itemAnnaDidntConsume;
        private int _brianChargedAnna;
        private String _brianOverchargedAnna;

        Result(List<Integer> costOfEachMeal, int itemAnnaDidntConsume, int brianChargedAnna) {
            _costOfEachMeal = costOfEachMeal;
            _itemAnnaDidntConsume = itemAnnaDidntConsume;
            _brianChargedAnna = brianChargedAnna;
            _brianOverchargedAnna = "";

            _bonAppetit();
            printResult();
        }

            private void _bonAppetit() {
                final int annaCost = _calculateAnnaCost();
                _checkIfBrianOverchargedAnna(annaCost);
            }

                private int _calculateAnnaCost() {
                    final int sum = _costOfEachMeal.stream().mapToInt(Integer::intValue).sum();
                    final int annaCost = (sum - _costOfEachMeal.get(_itemAnnaDidntConsume)) / 2;
                    return annaCost;
                }

                private void _checkIfBrianOverchargedAnna(int annaCost) {
                    if (annaCost == _brianChargedAnna)
                        _brianOverchargedAnna = "Bon Appetit";
                    else {
                        final int brianOverchargedAnna = _brianChargedAnna - annaCost;
                        _brianOverchargedAnna = Integer.toString(brianOverchargedAnna);
                    }
                }

            public void printResult() {
                System.out.println(_brianOverchargedAnna);
            }
    }
