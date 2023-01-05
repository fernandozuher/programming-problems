// Source: https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)


func main() {
    scanner := bufio.NewScanner(os.Stdin)

    var pageQuantity []int = readLineAsIntArray(scanner)
    var page []int = readLineAsIntArray(scanner)

    var result int = drawingBook(pageQuantity[0], page[0])
    fmt.Print(result)
}

    func readLineAsIntArray(scanner *bufio.Scanner) []int {
        var inputLine string

        if scanner.Scan() {
            inputLine = scanner.Text()
        } else {
            checkError(scanner.Err())
        }

        inputStringArray := strings.Split(inputLine, " ")
        numbers := make([]int, len(inputStringArray))

        for i, stringNumber := range inputStringArray {
            number, err := strconv.Atoi(stringNumber)
            checkError(err)
            numbers[i] = number
        }
        return numbers
    }

        func checkError(err error) {
            if err != nil {
                panic(err)
            }
        }

    func drawingBook(pageQuantity int, page int) int {
        var turnOfPagesFromFront int = calculateTurnOfPages(page)
        
        var maximumTurns int = calculateTurnOfPages(pageQuantity)

        var turnOfPagesFromBack int = maximumTurns - turnOfPagesFromFront

        var minimumTurnOfPages int = int(math.Min(float64(turnOfPagesFromFront), float64(turnOfPagesFromBack)))
        return minimumTurnOfPages
    }

        func calculateTurnOfPages(page int) int {
            if page & 1 == 1 {
                return pageIsOdd(page)
            } else {
                return pageIsEven(page)
            }
        }

            func pageIsOdd(page int) int {
                return (page - 1) / 2
            }

            func pageIsEven(page int) int {
                return page / 2
            }
