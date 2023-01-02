// Source: https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

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

    readLineAsIntArray(scanner)
    chocolateSquares := readLineAsIntArray(scanner)
    dayMonth := readLineAsIntArray(scanner)

    result := birthday(chocolateSquares, dayMonth)
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

    func birthday(chocolateSquares []int, dayMonth []int) int {
        waysBarCanBeDivided := 0
        day := dayMonth[0]
        month := dayMonth[1]

        for i, n1 := 0, len(chocolateSquares) - month + 1; i < n1; i++ {
            sum := 0
            for j, n2 := i, i + month; j < n2; j++ {
                sum += chocolateSquares[j]
            }

            if sum == day {
                waysBarCanBeDivided++
            }
        }
        return waysBarCanBeDivided
    }
