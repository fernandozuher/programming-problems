// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true
// Java 25

import morfo.io.Reader;

void main() {
    int[] lettersHeights = Reader.read(26, Integer::parseInt).stream().mapToInt(Integer::intValue).toArray();
    String word = Reader.read(s -> s);
    IO.println(designerPdfViewer(lettersHeights, word));
}

// n: length word, <= 10
// T: O(10) = O(1)
// S: O(1) extra space
int designerPdfViewer(int[] lettersHeights, String word) {
    return word.chars().map(ch -> lettersHeights[ch - 'a']).max().orElse(0) * word.length();
}
