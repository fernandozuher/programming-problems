// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true
// Java 25

import java.lang.IO;
import java.util.stream.Stream;

void main() {
    int[] lettersHeights = readNumbers();
    String word = IO.readln();
    IO.println(designerPdfViewer(lettersHeights, word));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

int designerPdfViewer(int[] lettersHeights, String word) {
    return word.chars().map(letter -> lettersHeights[letter - 'a']).max().orElse(0) * word.length();
}
