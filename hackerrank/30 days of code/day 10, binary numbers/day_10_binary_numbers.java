import java.io.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bufferedReader.readLine().trim());
        int max_ones = 0, ones;
        
        for (ones = 0; n > 0; n /= 2) {
            if (n % 2 == 1)
                ++ones;
            else {
                if (ones > max_ones)
                    max_ones = ones;
                ones = 0;
            }
        }

        System.out.println(ones > max_ones ? ones : max_ones);

        bufferedReader.close();
    }
}
