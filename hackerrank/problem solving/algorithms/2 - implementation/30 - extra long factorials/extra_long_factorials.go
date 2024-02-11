// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

package main

import (
    "fmt"
    "math/big"
)

func main() {
    var number int
    fmt.Scan(&number)
    var factorial *big.Int = calculateFactorialOf(number)
    fmt.Println(factorial)
}

    func calculateFactorialOf(number int) *big.Int {
        var factorial *big.Int = big.NewInt(1)
        for currentNumber := 2; currentNumber <= number; currentNumber++ {
            factorial.Mul(factorial, big.NewInt(int64(currentNumber)))
        }
        return factorial
    }
