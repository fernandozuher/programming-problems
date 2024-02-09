// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String args[]) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        int jumpLength = scan.nextInt();
        List<Integer> array = readIntArray(n);

        var obj = new JumpingOnTheClouds(array, jumpLength);
        System.out.println(obj.remainingEnergy());
    }

        private static List<Integer> readIntArray(final int n) {
            return Arrays.asList(new Integer[n]).stream().map(x -> scan.nextInt()).collect(toList());
        }
}

    class JumpingOnTheClouds {
        private List<Integer> clouds;
        private int jumpLength;
        private int energy;

        public JumpingOnTheClouds(final List<Integer> clouds, final int jumpLength) {
            this.clouds = clouds;
            this.jumpLength = jumpLength;
            this.energy = 100;
            calculateRemainingEnergy();
        }

            private void calculateRemainingEnergy() {
                for (int cloudIndex = 0; true;) {
                    energy -= spentEnergyAccordingToTypeOfCloud(clouds.get(cloudIndex));
                    cloudIndex = generateNewCloudIndex(cloudIndex);
                    if (isCloudIndexBackToFirstCloud(cloudIndex))
                        break;
                }
            }

                private int spentEnergyAccordingToTypeOfCloud(final int cloudType) {
                    return cloudType == 0 ? 1 : 3;
                }

                private int generateNewCloudIndex(final int cloudIndex) {
                    return (cloudIndex + jumpLength) % clouds.size();
                }

                private boolean isCloudIndexBackToFirstCloud(final int cloudIndex) {
                    return cloudIndex == 0;
                }

        public int remainingEnergy() {
            return energy;
        }
    }
