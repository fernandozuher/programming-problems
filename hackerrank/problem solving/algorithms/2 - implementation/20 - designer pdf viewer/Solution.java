// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;
import static java.util.stream.Collectors.toList;

public class Solution {
    private static Scanner scan;

    public static void main(String[] args) {
        scan = new Scanner(System.in);

        List<Integer> lettersHeights = readIntArray();
        String word = scan.nextLine();

        var obj = new DesignerPdfViewer(lettersHeights, word);
        System.out.println(obj.area());
    }

    private static List<Integer> readIntArray() {
        return Stream.of(scan.nextLine().split(" "))
               .map(Integer::parseInt)
               .collect(toList());
    }
}

    class DesignerPdfViewer {
        private List<Integer> lettersHeights;
        private String word;
        private int areaSize;

        public DesignerPdfViewer(final List<Integer> lettersHeights, final String word) {
            this.lettersHeights = lettersHeights;
            this.word = word;
            areaSize = 0;
            calculateArea();
        }

            private void calculateArea() {
                int maxHeight = 0;

                for (final char letter : word.toCharArray()) {
                    int letterIndex = letter - 'a';
                    int letterHeight = lettersHeights.get(letterIndex);
                    maxHeight = Math.max(maxHeight, letterHeight);
                }

                areaSize = maxHeight * word.length();
            }

        public int area() {
            return areaSize;
        }
    }
