// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    nNumberDivisors := make([]int, n)

    for i := 0; i < n; i++ {
        var number int
        fmt.Scanf("%d", &number)
        nNumberDivisors[i] = findNumberDivisorsQuantity(number)
    }

    printArray(nNumberDivisors)
}

    func findNumberDivisorsQuantity(number int) int {
        var divisors int = 0

        for currentNumber := number; currentNumber != 0; currentNumber = removeLastDigitOfNumber(currentNumber) {
            var divisor int = getLastDigitOfNumber(currentNumber)
            if isNumberEvenlyDividedByDivisor(number, divisor) {
                divisors++
            }
        }

        return divisors
    }

        func getLastDigitOfNumber(number int) int {
            return number % 10
        }

        func isNumberEvenlyDividedByDivisor(number int, divisor int) bool {
            return divisor != 0 && number%divisor == 0
        }

        func removeLastDigitOfNumber(number int) int {
            return number / 10
        }

    func printArray(array []int) {
        for _, x := range array {
            fmt.Println(x)
        }
    }
