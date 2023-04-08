// Source: https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    var nTestCases int = ReadANumber()
    var output []int = make([]int, nTestCases)

    for i := 0; i < nTestCases; i++ {
        var begin int = ReadANumber()
        var end int = ReadANumber()
        output[i] = CalculateNumberOfSquareIntegersInRange(begin, end)
    }

    PrintArray(output)
}

    func ReadANumber() int {
        var number int
        fmt.Scan(&number)
        return number
    }

    func CalculateNumberOfSquareIntegersInRange(begin int, end int) int {
        var squares int = 0
        for number := FindFirstSquareIntegerFromNumber(begin); IsPowerOf2OfNumberLessThanOrEqualToLimit(number, end); number++ {
            squares++
        }
        return squares
    }

        func FindFirstSquareIntegerFromNumber(number int) int {
            var squareRootNumber float64 = math.Sqrt(float64(number))
            var squareInteger int = GetSquareIntegerFromNumber(squareRootNumber)
            return squareInteger
        }

            func GetSquareIntegerFromNumber(number float64) int {
                var integerPart float64 = math.Trunc(number)
                if number != integerPart {
                    integerPart++
                }
                return int(integerPart)
            }

        func IsPowerOf2OfNumberLessThanOrEqualToLimit(number int, limit int) bool {
            return math.Pow(float64(number), 2.0) <= float64(limit)
        }

    func PrintArray(array []int) {
        for _, element := range array {
            fmt.Println(element)
        }
    }
