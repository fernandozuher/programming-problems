// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true
// Java 25

void main() {
    int[] lettersHeights = readNumbers();
    String word = IO.readln();
    IO.println(designerPdfViewer(lettersHeights, word));
}

int[] readNumbers() {
    return Stream.of(IO.readln().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// n: length word, <= 10
// T: O(10) = O(1)
// S: O(1) extra space
int designerPdfViewer(int[] lettersHeights, String word) {
    return word.chars().map(ch -> lettersHeights[ch - 'a']).max().orElse(0) * word.length();
}
