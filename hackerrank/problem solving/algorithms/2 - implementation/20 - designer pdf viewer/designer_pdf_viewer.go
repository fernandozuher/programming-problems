// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

package main

import "fmt"

const alphabetSize = 26

func main() {
    lettersHeights := readInput()
    var word string
    _, _ = fmt.Scan(&word)
    fmt.Println(designerPdfViewer(lettersHeights, word))
}

func readInput() [alphabetSize]int {
    var arr [alphabetSize]int
    for i := range alphabetSize {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n_w: length of string word, no more than 10 letters
// T = O(10) = O(1)
// S = O(1) extra space
func designerPdfViewer(lettersHeights [alphabetSize]int, word string) int {
    maxHeight := 0
    for _, ch := range word {
        height := lettersHeights[int(ch)-int('a')]
        maxHeight = max(maxHeight, height)
    }
    return maxHeight * len(word)
}
