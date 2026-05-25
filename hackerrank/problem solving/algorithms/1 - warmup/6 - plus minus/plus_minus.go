// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    arr := readNumbers(n)
    ratios := plusMinus(arr)
    printRatios(ratios)
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
func plusMinus(arr []int) []float64 {
    positive, negative, zero := 0, 0, 0

    for _, number := range arr {
        if number > 0 {
            positive++
        } else if number < 0 {
            negative++
        } else {
            zero++
        }
    }

    n := float64(len(arr))
    positiveRatio := float64(positive) / n
    negativeRatio := float64(negative) / n
    zeroRatio := float64(zero) / n
    return []float64{positiveRatio, negativeRatio, zeroRatio}
}

func printRatios(ratios []float64) {
    for _, ratio := range ratios {
        fmt.Printf("%.6f\n", ratio)
    }
}
