// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true
// Go 1.22

package main

import (
    "fmt"
    "slices"
)

func main() {
    var n int
    fmt.Scan(&n)
    candles := readNumbers(n)
    fmt.Println(birthdayCakeCandles(candles))
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range n {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func birthdayCakeCandles(candles []int) int {
    return count(candles, slices.Max(candles))
}

func count(numbers []int, value int) int {
    count := 0
    for _, x := range numbers {
        if x == value {
            count++
        }
    }
    return count
}
