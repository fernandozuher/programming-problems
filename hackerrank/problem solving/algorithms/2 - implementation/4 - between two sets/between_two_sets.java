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

    private List<Integer> _potentialFactors, _setA, _setB;
    private int _totalFactors;

    private void findFactors() {
        findNumbersDivisibleBySetA();
        findFactorsOfSetB();
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

            _totalFactors = _potentialFactors.stream().reduce(0, (previousResult, item) -> item != 0 ? ++previousResult : previousResult);
        }

    public Result() {
        readInput();
        _potentialFactors = new ArrayList<Integer>();
        _totalFactors = 0;
        findFactors();
    }

        private void readInput() {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

            try {
                Stream.of(bufferedReader.readLine());

                _setA = Stream.of(bufferedReader.readLine().split(" "))
                        .map(Integer::parseInt)
                        .collect(toList());

                _setB = Stream.of(bufferedReader.readLine().split(" "))
                        .map(Integer::parseInt)
                        .collect(toList());
            } catch (Exception e) {
                System.out.println("Exception caught during reading");
            }
        }

    public int getTotalX() {
        return _totalFactors;
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        Result result = new Result();
        int total = result.getTotalX();
        System.out.println(total);
    }
}
