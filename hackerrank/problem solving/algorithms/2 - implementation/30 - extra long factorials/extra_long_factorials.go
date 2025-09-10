// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

package main

import (
    "fmt"
    "math/big"
)

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    fmt.Println(factorial(n))
}

func factorial(n int) *big.Int {
    res := big.NewInt(1)
    for i := 2; i <= n; i++ {
        res.Mul(res, big.NewInt(int64(i)))
    }
    return res
}
