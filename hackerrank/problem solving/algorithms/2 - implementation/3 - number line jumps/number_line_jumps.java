// Source: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

import java.io.*;
import java.util.*;

class Result {

    /*
     * Complete the 'kangaroo' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. INTEGER x1
     *  2. INTEGER v1
     *  3. INTEGER x2
     *  4. INTEGER v2
     */

    public static String kangaroo(int x1, int v1, int x2, int v2) {
        if (v2 >= v1)
            return "NO";
        for (; x1 < x2; x1 += v1, x2 += v2);
        return x1 == x2 ? "YES" : "NO";
    }
}

public class Solution {

    public static int[] readInputAsIntArray() {
        final Scanner lineScanner = new Scanner(System.in);
        int[] numbers = new int[4];

        for (int i = 0; i < 4; i++)
            numbers[i] = lineScanner.nextInt();
        lineScanner.close();

        return numbers;
    }

    public static void main(String[] args) throws IOException {
        
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));
        
        int[] numbers = readInputAsIntArray();
        int x1 = numbers[0];
        int v1 = numbers[1];
        int x2 = numbers[2];
        int v2 = numbers[3];

        String result = Result.kangaroo(x1, v1, x2, v2);
        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();
    }
}
