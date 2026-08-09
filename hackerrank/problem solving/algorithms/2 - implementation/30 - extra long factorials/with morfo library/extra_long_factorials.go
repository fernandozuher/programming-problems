// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

package main

import (
    "fmt"
    "math/big"
    "morfo/morfoio"
)

func main() {
    n := morfoio.Read[int64]()
    fmt.Println(factorial(n))
}

// T: O(n)
// S: O(1) extra space (excluding the size of the resulting integer)
func factorial(n int64) *big.Int {
    res := big.NewInt(1)
    for i := int64(2); i <= n; i++ {
        res.Mul(res, big.NewInt(i))
    }
    return res
}
