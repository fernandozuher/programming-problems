// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

package main

import (
    "fmt"
    "slices"
)

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    fmt.Println(birthdayCakeCandles(readNumbers(n)))
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
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
