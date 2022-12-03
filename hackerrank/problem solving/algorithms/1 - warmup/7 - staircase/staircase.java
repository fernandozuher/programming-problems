import java.io.*;

class Result {

    /*
     * Complete the 'staircase' function below.
     *
     * The function accepts INTEGER n as parameter.
     */

    public static void staircase(int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n - i; j++)
                System.out.print(" ");
            for (int k = 0; k < i; k++)
                System.out.print("#");
            System.out.print("\n");
        }
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bufferedReader.readLine().trim());
        Result.staircase(n);
        bufferedReader.close();
    }
}
