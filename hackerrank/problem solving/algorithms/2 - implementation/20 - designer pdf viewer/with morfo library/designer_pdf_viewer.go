// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

const alphabetSize = 26

func main() {
    lettersHeights := readInput()
    word := morfoio.Read[string]()
    fmt.Println(designerPdfViewer(lettersHeights, word))
}

func readInput() [alphabetSize]int {
    var arr [alphabetSize]int
    copy(arr[:], morfoio.ReadN[int](alphabetSize))
    return arr
}

// n: length word, <= 10
// T: O(10) = O(1)
// S: O(1) extra space
func designerPdfViewer(lettersHeights [alphabetSize]int, word string) int {
    maxHeight := 0
    for _, ch := range word {
        maxHeight = max(maxHeight, lettersHeights[int(ch)-int('a')])
    }
    return maxHeight * len(word)
}
