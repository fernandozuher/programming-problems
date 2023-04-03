// Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var nTestCases int = ReadANumber()
    var output []int = make([]int, nTestCases)

    for i := 0; i < nTestCases; i++ {
        var number int = ReadANumber()
        output[i] = FindNumberDivisorsQuantity(number)
    }

    PrintOutput(output)
}

    func ReadANumber() int {
        var number int
        fmt.Scan(&number)
        return number
    }

    func FindNumberDivisorsQuantity(number int) int {
        var divisors int = 0

        for currentNumber := number; currentNumber != 0; currentNumber = RemoveLastDigitOfNumber(currentNumber) {
            var divisor int = GetLastDigitOfNumber(currentNumber)
            if IsNumberEvenlyDividedByDivisor(number, divisor) {
                divisors++
            }
        }

        return divisors
    }

        func GetLastDigitOfNumber(number int) int {
            return number % 10
        }

        func IsNumberEvenlyDividedByDivisor(number int, divisor int) bool {
            return divisor != 0 && number%divisor == 0
        }

        func RemoveLastDigitOfNumber(number int) int {
            return number / 10
        }

    func PrintOutput(array []int) {
        for _, number := range array {
            fmt.Println(number)
        }
    }
