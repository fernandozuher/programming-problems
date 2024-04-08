// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import static java.util.stream.Collectors.toList;

public class Solution {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        int n = scan.nextInt();
        List<Integer> clouds = Arrays.asList(new Integer[n]).stream().map(x -> scan.nextInt()).collect(toList());
        System.out.println(minimumNumberOfJumps(clouds));
    }

        public static int minimumNumberOfJumps(List<Integer> clouds) {
            int jumps = 0;
            for (int i = 0, n = clouds.size() - 1; i < n; ++jumps)
                i += nextJump(i, clouds);
            return jumps;
        }

            public static int nextJump(int index, List<Integer> clouds) {
                boolean isNextSecondCloudCumulus = false;
                if (index + 2 < clouds.size())
                    isNextSecondCloudCumulus = clouds.get(index + 2) == 0;
                return isNextSecondCloudCumulus ? 2 : 1;
            }
}
