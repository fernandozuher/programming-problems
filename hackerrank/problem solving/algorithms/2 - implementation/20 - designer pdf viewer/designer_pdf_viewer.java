// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

import java.util.*;
import java.util.stream.Stream;

class Solution {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int[] lettersHeights = readNumbers(scan);
            String word = scan.nextLine();
            System.out.println(designerPdfViewer(lettersHeights, word));
        }
    }

    private static int[] readNumbers(Scanner scan) {
        return Stream.of(scan.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    private static int designerPdfViewer(int[] lettersHeights, String word) {
        return word.chars()
                .map(letter -> lettersHeights[letter - 'a'])
                .max()
                .orElse(0) * word.length();
    }
}
