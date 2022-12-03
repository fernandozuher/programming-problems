import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

public class Solution {

    static int bubbleSort(List<Integer> a) {

        int numberOfSwaps = 0;

        for (var _i : a) {
            for (int j = 0, N = a.size() - 1; j < N; j++)

                if (a.get(j) > a.get(j + 1)) {
                    Collections.swap(a, j, j+1);
                    numberOfSwaps++;
                }

            if (numberOfSwaps == 0)
                break;
        }
        return numberOfSwaps;
    }

    public static void main(String[] args) throws IOException {

        var bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        final int N = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> list = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        System.out.format("Array is sorted in %d swaps.", bubbleSort(list));
        System.out.format("\nFirst Element: %d", list.get(0));
        System.out.format("\nLast Element: %d", list.get(list.size() - 1));

        bufferedReader.close();
    }
}
