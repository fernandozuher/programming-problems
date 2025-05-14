// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var testCases int
    fmt.Scan(&testCases)
    for range testCases {
        var n, k int
        fmt.Scan(&n, &k)
        fmt.Println(bitwiseAnd(n, k))
    }
}

func bitwiseAnd(n int, k int) int {
    if (k - 1 | k) <= n {
        return k - 1
    }
    return k - 2
}
