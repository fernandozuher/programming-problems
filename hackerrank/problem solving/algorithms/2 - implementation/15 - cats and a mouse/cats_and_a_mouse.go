// Source: https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

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

    var inputLine []int = readLineAsIntArray(scanner)
    var n int = inputLine[0]

    var inputLines [][]int = readCatsAndMousePositionsLines(scanner, n)

    catAndMouse(inputLines)
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

    func readCatsAndMousePositionsLines(scanner *bufio.Scanner, n int) [][]int {
        var inputLines [][]int = make([][]int, n)

        for i := 0; i < n; i++ {
            inputLines[i] = readLineAsIntArray(scanner)
        }

        return inputLines
    }

    func catAndMouse(catsAndMousePositionsLines [][]int) {
        for _, catsAndMousePositions := range catsAndMousePositionsLines {
            var result string = findNearestCatOrNot(catsAndMousePositions)
            fmt.Println(result)
        }
    }

        func findNearestCatOrNot(catsAndMousePositions []int) string {
            var catAPosition int = catsAndMousePositions[0]
            var catBPosition int = catsAndMousePositions[1]
            var mousePosition int = catsAndMousePositions[2]

            var catAPositionDifference int = int(math.Abs(float64(catAPosition) - float64(mousePosition)))
            var catBPositionDifference int = int(math.Abs(float64(catBPosition) - float64(mousePosition)))

            var result string = getStringResult(catAPositionDifference, catBPositionDifference)

            return result
        }

            func getStringResult(catAPositionDifference int, catBPositionDifference int) string {
                var result string

                if catAPositionDifference < catBPositionDifference {
                    result = "Cat A"
                } else if catAPositionDifference > catBPositionDifference {
                    result = "Cat B"
                } else {
                    result = "Mouse C"
                }

                return result
            }
