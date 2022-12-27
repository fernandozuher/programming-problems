import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'getTotalX' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER_ARRAY a
     *  2. INTEGER_ARRAY b
     */

    private List<Integer> _setA, _setB, _potentialFactors;
    private int _totalFactors;

    private void findFactors() {
        findNumbersDivisibleBySetA();
        findFactorsOfSetB();
        countFactors();
    }

        private void findNumbersDivisibleBySetA() {
            int lastElementOfSetA = _setA.get(_setA.size() - 1);

            for (int potentialFactor = lastElementOfSetA; potentialFactor <= _setB.get(0); potentialFactor += lastElementOfSetA) {
                boolean isARealPotentialFactor = true;

                for (int elementA : _setA)
                    if (potentialFactor % elementA != 0) {
                        isARealPotentialFactor = false;
                        break;
                    }

                if (isARealPotentialFactor)
                    _potentialFactors.add(potentialFactor);
            }
        }

        private void findFactorsOfSetB() {
            for (int elementB : _setB)
                for (int i = 0; i < _potentialFactors.size(); i++)
                    if (_potentialFactors.get(i) != 0 && elementB % _potentialFactors.get(i) != 0)
                        _potentialFactors.set(i, 0);
        }

        private void countFactors() {
            _totalFactors = _potentialFactors.stream().reduce(0, (previousResult, item) -> item != 0 ? ++previousResult : previousResult);
        }

    public Result(List<Integer> setA, List<Integer> setB) {
        _setA = new ArrayList<Integer>(setA);
        _setB = new ArrayList<Integer>(setB);
        _potentialFactors = new ArrayList<Integer>();
        _totalFactors = 0;

        findFactors();

        printResult();
    }

        public void printResult() {
            System.out.println(_totalFactors);
        }
}

public class Solution {

    private static List<Integer> readLineAsIntegerList(BufferedReader bufferedReader)  {
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

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        readLineAsIntegerList(bufferedReader);
        List<Integer> setA = readLineAsIntegerList(bufferedReader);
        List<Integer> setB = readLineAsIntegerList(bufferedReader);

        Collections.sort(setA);
        Collections.sort(setB);

        Result result = new Result(setA, setB);
    }
}