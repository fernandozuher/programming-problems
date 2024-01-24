// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        int n = scan.nextInt();
        scan.nextLine();
        List<String> nearestCatsOrNot = new ArrayList<>(Arrays.asList(new String[n]));

        for (int i = 0; i < n; ++i) {
            List<Integer> positions = readIntArray();
            CatsAndAMouse obj = new CatsAndAMouse(positions);
            nearestCatsOrNot.set(i, obj.nearestCatOrNot());
        }

        nearestCatsOrNot.forEach(System.out::println);
    }

        private static List<Integer> readIntArray() {
            return Stream.of(scan.nextLine().split(" "))
                   .map(Integer::parseInt)
                   .collect(toList());
        }
}

    class CatsAndAMouse {
        private int catAPosition;
        private int catBPosition;
        private int mousePosition;
        private String closestCatOrNot;

        public CatsAndAMouse(final List<Integer> catsAndMousePositions) {
            catAPosition = catsAndMousePositions.get(0);
            catBPosition = catsAndMousePositions.get(1);
            mousePosition = catsAndMousePositions.get(2);
            closestCatOrNot = "";
            findNearestCatOrNot();
        }

            private void findNearestCatOrNot() {
                int catAPositionFromMouse = Math.abs(catAPosition - mousePosition);
                int catBPositionFromMouse = Math.abs(catBPosition - mousePosition);

                if (catAPositionFromMouse < catBPositionFromMouse)
                    closestCatOrNot = "Cat A";
                else if (catAPositionFromMouse > catBPositionFromMouse)
                    closestCatOrNot = "Cat B";
                else
                    closestCatOrNot = "Mouse C";
            }

        public String nearestCatOrNot() {
            return closestCatOrNot;
        }
    }
