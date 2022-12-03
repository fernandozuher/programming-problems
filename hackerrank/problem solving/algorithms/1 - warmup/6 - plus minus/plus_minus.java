import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'plusMinus' function below.
     *
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static void plusMinus(List<Integer> arr) {
        int positiveQuantity = 0;
        int negativeQuantity = 0;
        int zeroQuantity = 0;

        for (var number : arr)
            if (number > 0)
                positiveQuantity++;
            else if (number < 0)
                negativeQuantity++;
            else
                zeroQuantity++;

        int n = arr.size();
        float positiveValuesProportion = (float) positiveQuantity / n;
        float negativeValuesProportion = (float) negativeQuantity / n;
        float zeroValuesProportion = (float) zeroQuantity / n;

        System.out.printf("%.6f\n", positiveValuesProportion);
        System.out.printf("%.6f\n", negativeValuesProportion);
        System.out.printf("%.6f\n", zeroValuesProportion);
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                            .map(Integer::parseInt)
                            .collect(toList());

        Result.plusMinus(arr);

        bufferedReader.close();
    }
}
