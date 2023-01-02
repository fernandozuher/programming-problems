// Source: https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=truehttps://www.hackerrank.com/challenges/the-divisibleSumPairs-bar/problem?isFullScreen=true

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)

    input1 := readLineAsIntArray(scanner)
    k := input1[1]
    numbers := readLineAsIntArray(scanner)
    
    sort.Ints(numbers)

    result := divisibleSumPairs(numbers, k)
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

    func divisibleSumPairs(numbers []int, k int) int {
        nDivisibleSumPairs := 0
        
        for i, n1 := 0, len(numbers) - 1; i < n1; i++ {
            for j := i + 1; j < len(numbers); j++ {
                if numbers[i] <= numbers[j] && ((numbers[i] + numbers[j]) % k == 0) {
                    nDivisibleSumPairs++
                }
            }
        }

        return nDivisibleSumPairs
    }
