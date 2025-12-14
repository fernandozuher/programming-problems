// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
    "math/bits"
    "strconv"
)

func main() {
    var lower, upper uint64
    _, _ = fmt.Scan(&lower, &upper)

    validRange := false
    for num := lower; num <= upper; num++ {
        if isNumberKaprekar(num) {
            fmt.Print(num, " ")
            validRange = true
        }
    }

    if !validRange {
        fmt.Println("INVALID RANGE")
    }
}

func isNumberKaprekar(n uint64) bool {
    squareNumber := uint64(math.Pow(float64(n), 2.0))
    divisor := uint64(math.Pow(10.0, float64(numberDigits(n))))
    leftNumber, rightNumber := bits.Div64(0, squareNumber, divisor)
    return n == leftNumber+rightNumber
}

func numberDigits(n uint64) int {
    return len(strconv.Itoa(int(n)))
}
