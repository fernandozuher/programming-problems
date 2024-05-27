// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true
// From Go 1.22

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    fmt.Print(birthdayCakeCandles(n))
}

func birthdayCakeCandles(n int) int {
    maxElement, maxCount := 0, 0

    for range n {
        var x int
        fmt.Scan(&x)
        if x > maxElement {
            maxElement = x
            maxCount = 1
        } else if x == maxElement {
            maxCount++
        }
    }

    return maxCount
}
