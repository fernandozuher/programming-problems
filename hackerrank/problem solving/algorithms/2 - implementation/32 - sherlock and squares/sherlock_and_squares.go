// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    fmt.Scan(&n)
    output := make([]int, n)

    for i := 0; i < n; i++ {
        var begin, end int
        fmt.Scanf("%d %d", &begin, &end)
        output[i] = calculateQuantityOfSquareIntegersInRange(begin, end)
    }

    printArray(output)
}

    func calculateQuantityOfSquareIntegersInRange(begin int, end int) int {
        squares := 0
        for number := findFirstSquareInteger(begin); isPowerOf2LessThanOrEqualToLimit(number, end); number++ {
            squares++
        }
        return squares
    }

        func findFirstSquareInteger(x int) int {
            var squareRoot float64 = math.Sqrt(float64(x))
            var integerPart float64 = math.Trunc(squareRoot)
            if squareRoot != integerPart {
                integerPart++
            }
            return int(integerPart)
        }

        func isPowerOf2LessThanOrEqualToLimit(x int, limit int) bool {
            return math.Pow(float64(x), 2.0) <= float64(limit)
        }

    func printArray(array []int) {
        for _, element := range array {
            fmt.Println(element)
        }
    }
