// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)

    var lettersHeights []int = readIntArray(scanner)
    scanner.Scan()
    var word string = scanner.Text()

    fmt.Println(designerPdfViewer(lettersHeights, word))
}

    func readIntArray(scanner *bufio.Scanner) []int {
        if scanner.Scan() {
            lineArray := strings.Split(scanner.Text(), " ")
            intArray := make([]int, len(lineArray))

            for i, element := range lineArray {
                intArray[i], _ = strconv.Atoi(element)
            }

            return intArray
        }

        return []int{}
    }

    func designerPdfViewer(lettersHeights []int, word string) int {
        maxHeight := 0

        for _, letter := range word {
            var letterIndex int = int(letter) - int('a')
            var letterHeight int = lettersHeights[letterIndex]

            if maxHeight < letterHeight {
                maxHeight = letterHeight
            }
        }

        var area int = maxHeight * len(word)
        return area
    }
