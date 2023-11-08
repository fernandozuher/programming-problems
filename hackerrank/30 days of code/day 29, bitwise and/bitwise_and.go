// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)

    for i := 0; i < n; i++ {
        var count, lim int
        fmt.Scan(&count, &lim)
        fmt.Println(bitwiseAnd(count, lim))
    }
}

func bitwiseAnd(n int, k int) int {
    var maximumValueLessThanK int = 0

    for i := 1; i <= n; i++ {
        for j := i + 1; j <= n; j++ {
            var operation int = i & j

            if operation < k && operation > maximumValueLessThanK {
                if operation == k-1 {
                    return operation
                } else {
                    maximumValueLessThanK = operation
                }
            }
        }
    }

    return maximumValueLessThanK
}
