// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    printRatios(plusMinus(readNumbers(n)))
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of array arr
// T: O(n)
// S: O(1) extra space
func plusMinus(arr []int) []float64 {
    positive, negative, zero := 0, 0, 0

    for _, x := range arr {
        if x > 0 {
            positive++
        } else if x < 0 {
            negative++
        } else {
            zero++
        }
    }

    n := len(arr)
    positiveRatio := float64(positive) / float64(n)
    negativeRatio := float64(negative) / float64(n)
    zeroRatio := float64(zero) / float64(n)
    return []float64{positiveRatio, negativeRatio, zeroRatio}
}

func printRatios(ratios []float64) {
    for _, ratio := range ratios {
        fmt.Printf("%.6f\n", ratio)
    }
}
