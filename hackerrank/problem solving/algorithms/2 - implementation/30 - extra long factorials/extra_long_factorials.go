// Source: https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

package main

import (
    "fmt"
    "math/big"
)

func main() {
    var number int = ReadANumber()
    var factorial *big.Int = CalculateFactorialOf(number)
    fmt.Println(factorial)
}

    func ReadANumber() int {
        var number int
        fmt.Scan(&number)
        return number
    }

    func CalculateFactorialOf(number int) *big.Int {
        var factorial *big.Int = big.NewInt(1)

        for i := 2; i <= number; i++ {
            factorial.Mul(factorial, big.NewInt(int64(i)))
        }

        return factorial
    }
