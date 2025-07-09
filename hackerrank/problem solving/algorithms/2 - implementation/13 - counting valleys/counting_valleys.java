// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            scan.nextLine();
            String steps = scan.nextLine();
            System.out.println(countingValleys(steps));
        }
    }

    private static int countingValleys(String steps) {
        int valleys = 0;
        int currentAltitude = 0;

        for (char step : steps.toCharArray()) {
            boolean wasBelowSeaLevel = currentAltitude < 0;
            currentAltitude += step == 'D' ? -1 : 1;
            boolean isInSeaLevelFromValley = wasBelowSeaLevel && currentAltitude == 0;
            if (isInSeaLevelFromValley) valleys++;
        }

        return valleys;
    }
}
