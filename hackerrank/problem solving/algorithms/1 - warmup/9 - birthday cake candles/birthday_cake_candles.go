// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

package main

import (
    "fmt"
    "slices"
)

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    candles := readNumbers(n)
    fmt.Println(birthdayCakeCandles(candles))
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of candles
// T: O(2n) = O(n)
// S: O(1) extra space
func birthdayCakeCandles(candles []int) int {
    return count(candles, slices.Max(candles))
}

func count(arr []int, value int) int {
    count := 0
    for _, x := range arr {
        if x == value {
            count++
        }
    }
    return count
}
