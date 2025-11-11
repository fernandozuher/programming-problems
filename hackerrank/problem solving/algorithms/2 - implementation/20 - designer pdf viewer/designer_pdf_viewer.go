// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

package main

import "fmt"

func main() {
    lettersHeights := readInput()
    var word string
    fmt.Scan(&word)
    fmt.Println(designerPdfViewer(lettersHeights, word))
}

func readInput() []int {
    arr := make([]int, 26)
    for i := range arr {
        fmt.Scan(&arr[i])
    }
    return arr
}

func designerPdfViewer(lettersHeights []int, word string) int {
    maxHeight := 0
    for _, letter := range word {
        index := int(letter) - int('a')
        if maxHeight < lettersHeights[index] {
            maxHeight = lettersHeights[index]
        }
    }
    return maxHeight * len(word)
}
