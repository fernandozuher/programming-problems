// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
    "slices"
)

func main() {
    morfoio.SkipInputLn();
    candles := morfoio.ReadLn[int]()
    fmt.Println(birthdayCakeCandles(candles))
}

// n: length of candles
// T: O(2n) = O(n)
// S: O(1) extra space
func birthdayCakeCandles(candles []int) int {
    return count(candles, slices.Max(candles))
}

func count[T comparable](arr []T, target T) int {
    count := 0
    for _, x := range arr {
        if x == target {
            count++
        }
    }
    return count
}
