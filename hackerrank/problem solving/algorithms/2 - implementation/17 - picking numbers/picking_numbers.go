// Source: https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

package main

import (
    "bufio"
    "fmt"
    "math"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)

    readLineAsIntArray(scanner)

    var numbers []int = readLineAsIntArray(scanner)
    sort.Ints(numbers)

    var result int = pickingNumbers(numbers)
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

    func pickingNumbers(numbers []int) int {
        var subarrayBiggestSize int = 0
        var firstReferenceNumberIndex int = 0
        var secondReferenceNumberIndex int = 0
        var subarrayCurrentSize int = 1

        for i, n := 1, len(numbers); i < n; i++ {
            var difference int = numbers[i] - numbers[firstReferenceNumberIndex]

            switch difference {
            case 0:
                subarrayCurrentSize++

            case 1:
                subarrayCurrentSize++
                if numbers[secondReferenceNumberIndex] != numbers[i] {
                    secondReferenceNumberIndex = i
                }

            default:
                subarrayBiggestSize = updateLongestSubarraySize(subarrayBiggestSize, subarrayCurrentSize)

                var update []int = updateFirstReferenceNumberIndexAndSubarrayCurrentSize(numbers, i, secondReferenceNumberIndex)

                firstReferenceNumberIndex = update[0]
                secondReferenceNumberIndex = i
                subarrayCurrentSize = update[1]
            }
        }

        subarrayBiggestSize = updateLongestSubarraySize(subarrayBiggestSize, subarrayCurrentSize)
        return subarrayBiggestSize
    }

        func updateLongestSubarraySize(subarrayBiggestSize int, subarrayCurrentSize int) int {
            return int(math.Max(float64(subarrayBiggestSize), float64(subarrayCurrentSize)))
        }

        func updateFirstReferenceNumberIndexAndSubarrayCurrentSize(numbers []int, i int, secondReferenceNumberIndex int) []int {
            var firstReferenceNumberIndex, subarrayCurrentSize int

            if numbers[i]-numbers[secondReferenceNumberIndex] == 1 {
                firstReferenceNumberIndex = secondReferenceNumberIndex
                subarrayCurrentSize = i - secondReferenceNumberIndex + 1
            } else {
                firstReferenceNumberIndex = i
                subarrayCurrentSize = 1
            }

            var result []int = []int{firstReferenceNumberIndex, subarrayCurrentSize}
            return result
        }
