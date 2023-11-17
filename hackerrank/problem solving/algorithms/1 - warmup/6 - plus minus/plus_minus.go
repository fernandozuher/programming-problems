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
        var positiveQuantity, negativeQuantity, zeroQuantity int = 0, 0, 0

        for _, number := range array {
            if number > 0 {
                positiveQuantity++
            } else if number < 0 {
                negativeQuantity++
            } else {
                zeroQuantity++
            }
        }

        n := float64(len(array))
        positiveValuesProportion := float64(positiveQuantity) / n
        negativeValuesProportion := float64(negativeQuantity) / n
        zeroValuesProportion := float64(zeroQuantity) / n

        fmt.Printf("%.6f\n", positiveValuesProportion)
        fmt.Printf("%.6f\n", negativeValuesProportion)
        fmt.Printf("%.6f\n", zeroValuesProportion)
    }
