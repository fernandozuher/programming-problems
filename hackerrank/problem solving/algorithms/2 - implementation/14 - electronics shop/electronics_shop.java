// Source: https://www.hackerrank.com/challenges/electronics-shop/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;


public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        List<Integer> newLine = readLineAsListInteger(bufferedReader);
        final int budget = newLine.get(0);

        List<Integer> keyboardCosts = readLineAsListInteger(bufferedReader);
        List<Integer> usbDriveCosts = readLineAsListInteger(bufferedReader);

        Collections.sort(keyboardCosts);
        Collections.sort(usbDriveCosts);

        Result result = new Result(keyboardCosts, usbDriveCosts, budget);
    }

        private static List<Integer> readLineAsListInteger(BufferedReader bufferedReader)  {
            try {
                var inputLine = Stream.of(bufferedReader.readLine().split(" "))
                              .map(Integer::parseInt)
                              .collect(toList());

                return inputLine;
            } catch (Exception e) {
                System.out.println("Exception caught during reading");
            }
            return null;
        }
}

    class Result {
        private List<Integer> _keyboardCosts;
        private List<Integer> _usbDriveCosts;
        private int _budget;
        private int _canBeSpent;

        public Result(List<Integer> keyboardCosts, List<Integer> usbDriveCosts, int budget) {
            _keyboardCosts = new ArrayList<Integer>(keyboardCosts);
            _usbDriveCosts = new ArrayList<Integer>(usbDriveCosts);
            _budget = budget;
            _canBeSpent = 0;

            _getMoneySpent();
            printResult();
        }

            private void _getMoneySpent() {
                for (int i = 0, n_keyboardCosts = _keyboardCosts.size(); i < n_keyboardCosts; i++) {

                    if (_isNextCostEqualToCurrentOne(_keyboardCosts, i))
                        continue;

                    for (int j = 0, n_usbDriveCosts = _usbDriveCosts.size(); j < n_usbDriveCosts; j++) {
                        
                        if (_isNextCostEqualToCurrentOne(_usbDriveCosts, j))
                            continue;

                        final int sum = _keyboardCosts.get(i) + _usbDriveCosts.get(j);

                        if (_isSumInsideBudget(sum))
                            _canBeSpent = _updateCost(sum);
                        else
                            break;
                    }
                }

                _canBeSpent = _canBeSpent > 0 ? _canBeSpent : -1;
            }

                private boolean _isNextCostEqualToCurrentOne(List<Integer> deviceCosts, int currentIndex) {
                    return currentIndex < deviceCosts.size() - 1 && deviceCosts.get(currentIndex) == deviceCosts.get(currentIndex + 1);
                }

                private boolean _isSumInsideBudget(int sum) {
                    return sum <= _budget;
                }

                private int _updateCost(int sum) {
                    return Math.max(sum, _canBeSpent);
                }

            public void printResult() {
                System.out.println(_canBeSpent);
            }
    }
