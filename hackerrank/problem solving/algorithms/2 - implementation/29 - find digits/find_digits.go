// Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var nTestCases int = readANumber()
    var output []int = make([]int, nTestCases)

    for i := 0; i < nTestCases; i++ {
        var number int = readANumber()
        output[i] = findNumberDivisorsQuantity(number)
    }

    printOutput(output)
}

    func readANumber() int {
        var number int
        fmt.Scan(&number)
        return number
    }

    func findNumberDivisorsQuantity(number int) int {
        var divisors int = 0

        for currentNumber := number; currentNumber != 0; currentNumber /= 10 {
            var potentialDivisor int = currentNumber % 10
            if isNumberEvenlyDividedByDivisor(number, potentialDivisor) {
                divisors++
            }
        }

        return divisors
    }

        func isNumberEvenlyDividedByDivisor(number int, divisor int) bool {
            return divisor != 0 && number%divisor == 0
        }

    func printOutput(array []int) {
        for _, number := range array {
            fmt.Println(number)
        }
    }
