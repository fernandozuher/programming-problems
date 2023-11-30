// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        AppleAndOrange input = readInput();
        countApplesAndOranges(input);
    }

        private static AppleAndOrange readInput() {
            int startingSam = scan.nextInt();
            int endingSam = scan.nextInt();
            int appleTreeLocation = scan.nextInt();
            int orangeTreeLocation = scan.nextInt();

            // Discard new line and sizes of arraays
            scan.nextLine();
            scan.nextLine();

            List<Integer> applesDistanceFromTree = readIntArray();
            List<Integer> orangesDistanceFromTree = readIntArray();

            return new AppleAndOrange(startingSam, endingSam,
                                      appleTreeLocation, orangeTreeLocation,
                                      applesDistanceFromTree, orangesDistanceFromTree);
        }

            private static List<Integer> readIntArray() {
                return Stream.of(scan.nextLine().split(" ")).map(Integer::parseInt).collect(toList());
            }

        private static void countApplesAndOranges(final AppleAndOrange input) {
            int applesOnHouse = countFruitsOnHouse(input, "apple");
            int orangesOnHouse = countFruitsOnHouse(input, "orange");
            System.out.println(applesOnHouse + "\n" + orangesOnHouse);
        }

            private static int countFruitsOnHouse(final AppleAndOrange input, final String fruit) {
                List<List<Integer>> filteredInput = filterInput(input, fruit);
                int treeLocation = filteredInput.get(0).get(0);
                List<Integer> fruits = filteredInput.get(1);

                return (int) fruits.stream().filter(partialLocation -> {
                    int location = treeLocation + partialLocation;
                    return location >= input.startingSam && location <= input.endingSam;
                }).count();
            }

                private static List<List<Integer>> filterInput(final AppleAndOrange input,
                        final String fruit) {
                    final int data = 2;
                    var filteredInput = new ArrayList<List<Integer>>(data);
                    filteredInput.add(new ArrayList<Integer>());
                    filteredInput.add(new ArrayList<Integer>());

                    if (fruit == "apple") {
                        filteredInput.get(0).add(input.appleTreeLocation);
                        filteredInput.set(1, input.applesDistanceFromTree);
                    } else {
                        filteredInput.get(0).add(input.orangeTreeLocation);
                        filteredInput.set(1, input.orangesDistanceFromTree);
                    }

                    return filteredInput;
                }
}

    class AppleAndOrange {
        public int startingSam, endingSam;
        public int appleTreeLocation, orangeTreeLocation;
        public List<Integer> applesDistanceFromTree, orangesDistanceFromTree;

        public AppleAndOrange(int startingSam, int endingSam,
                              int appleTreeLocation, int orangeTreeLocation,
                              List<Integer> applesDistanceFromTree,
                              List<Integer> orangesDistanceFromTree) {
            this.startingSam = startingSam;
            this.endingSam = endingSam;
            this.appleTreeLocation = appleTreeLocation;
            this.orangeTreeLocation = orangeTreeLocation;
            this.applesDistanceFromTree = applesDistanceFromTree;
            this.orangesDistanceFromTree = orangesDistanceFromTree;
        }
    }
