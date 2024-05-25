// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    var array []int = readIntArray(n)
    plusMinus(array)
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := 0; i < n; i++ {
            fmt.Scan(&array[i])
        }
        return array
    }

    func plusMinus(array []int) {
        var positive, negative, zero int = 0, 0, 0

        for _, number := range array {
            if number > 0 {
                positive++
            } else if number < 0 {
                negative++
            } else {
                zero++
            }
        }

        n := float64(len(array))
        positiveProportion := float64(positive) / n
        negativeProportion := float64(negative) / n
        zeroProportion := float64(zero) / n

        fmt.Printf("%.6f\n", positiveProportion)
        fmt.Printf("%.6f\n", negativeProportion)
        fmt.Printf("%.6f\n", zeroProportion)
    }
