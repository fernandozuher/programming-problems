// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    var nTests int
    fmt.Scan(&nTests)

    for range nTests {
        var n int
        fmt.Scan(&n)
        if isPrime(n) {
            fmt.Println("Prime")
        } else {
            fmt.Println("Not prime")
        }
    }
}

func isPrime(n int) bool {
    if n == 1 {
        return false
    }
    if n == 2 {
        return true
    }
    if n%2 == 0 {
        return false
    }

    limit := int(math.Sqrt(float64(n)))
    for divisor := 3; divisor <= limit; divisor += 2 {
        if n%divisor == 0 {
            return false
        }
    }
    return true
}
