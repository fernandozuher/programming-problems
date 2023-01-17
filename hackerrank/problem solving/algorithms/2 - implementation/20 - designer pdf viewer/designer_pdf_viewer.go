// Source: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem?isFullScreen=true

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

    var inputLine1 []int = readLineAsIntArray(scanner)
    var inputLine2 string = readLineAsString(scanner)

    var result int = designerPdfViewer(inputLine1, inputLine2)
    fmt.Print(result)
}

    func readLineAsIntArray(scanner *bufio.Scanner) []int {
        var line string

        if scanner.Scan() {
            line = scanner.Text()
        } else {
            checkError(scanner.Err())
        }

        inputStringArray := strings.Split(line, " ")
        inputLine := make([]int, len(inputStringArray))

        for i, stringNumber := range inputStringArray {
            number, err := strconv.Atoi(stringNumber)
            checkError(err)
            inputLine[i] = number
        }
        return inputLine
    }

        func checkError(err error) {
            if err != nil {
                panic(err)
            }
        }

    func readLineAsString(scanner *bufio.Scanner) string {
        var line string

        if scanner.Scan() {
            line = scanner.Text()
        } else {
            checkError(scanner.Err())
        }

        return line
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
