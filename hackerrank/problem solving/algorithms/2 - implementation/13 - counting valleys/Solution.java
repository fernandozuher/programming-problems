// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);

        int n = scan.nextInt();
        scan.nextLine();
        String array = scan.nextLine();

        var obj = new CountValleys(array);
        System.out.println(obj.traversedValleys());
    }
}

    class CountValleys {
        private String steps;
        private int nTraversedValleys;

        public CountValleys(final String steps) {
            this.steps = steps;
            nTraversedValleys = 0;
            countingValleys();
        }

            private void countingValleys() {
                int currentAltitude = 0;

                for (final char step : steps.toCharArray()) {
                    boolean wasTravessingAValley = currentAltitude < 0;
                    currentAltitude += step == 'D' ? -1 : 1;

                    if (isInSeaLevelFromValley(wasTravessingAValley, currentAltitude))
                        ++nTraversedValleys;
                }
            }

                private boolean isInSeaLevelFromValley(final boolean wasTravessingAValley, final int currentAltitude) {
                    return wasTravessingAValley && currentAltitude == 0;
                }

        public int traversedValleys() {
            return nTraversedValleys;
        }
    }
