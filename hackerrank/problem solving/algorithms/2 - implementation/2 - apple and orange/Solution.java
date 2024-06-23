// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true
// From Java 21

import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

class AppleAndOrange {
    public int startingSam, endingSam;
    public int appleTreeLocation, orangeTreeLocation;
    public int nApples, nOranges;
    public List<Integer> applesDistanceFromTree, orangesDistanceFromTree;
}

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);
        AppleAndOrange input = readInput();
        countApplesAndOranges(input);
    }

        public static AppleAndOrange readInput() {
            var input = new AppleAndOrange();
            input.startingSam = scan.nextInt();
            input.endingSam = scan.nextInt();
            input.appleTreeLocation = scan.nextInt();
            input.orangeTreeLocation = scan.nextInt();
            input.nApples = scan.nextInt();
            input.nOranges = scan.nextInt();
            input.applesDistanceFromTree = readIntArray(input.nApples);
            input.orangesDistanceFromTree = readIntArray(input.nOranges);
            return input;
        }

            public static List<Integer> readIntArray(final int n) {
                return Stream.of(new Integer[n]).map(_ -> scan.nextInt()).collect(toList());
            }

        public static void countApplesAndOranges(final AppleAndOrange input) {
            int applesOnHouse = countFruitsOnHouse(input, "apple");
            int orangesOnHouse = countFruitsOnHouse(input, "orange");
            System.out.println(applesOnHouse + "\n" + orangesOnHouse);
        }

            public static int countFruitsOnHouse(final AppleAndOrange input, final String fruit) {
                var temp = filterInput(input, fruit);
                var treeLocation = (int) temp.getFirst();
                var fruits = (List<Integer>) temp.getLast();

                return (int) fruits.stream().filter(partialLocation -> {
                    int location = treeLocation + partialLocation;
                    return location >= input.startingSam && location <= input.endingSam;
                }).count();
            }

                public static List <Object> filterInput(final AppleAndOrange input, final String fruit) {
                    return fruit.equals("apple") ?
                            List.of(input.appleTreeLocation, input.applesDistanceFromTree)
                            : List.of(input.orangeTreeLocation, input.orangesDistanceFromTree);
                }
}
