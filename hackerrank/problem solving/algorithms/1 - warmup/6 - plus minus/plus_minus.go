// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    numbers := readNumbers(n)
    ratios := plusMinus(numbers)
    printRatios(ratios)
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range numbers {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func plusMinus(numbers []int) (ratios []float64) {
    positive, negative, zero := 0, 0, 0

    for _, x := range numbers {
        if x > 0 {
            positive++
        } else if x < 0 {
            negative++
        } else {
            zero++
        }
    }

    n := len(numbers)
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
