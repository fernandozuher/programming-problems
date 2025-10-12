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
    for number := lower; number <= upper; number++ {
        if isNumberKaprekar(number) {
            fmt.Print(number, " ")
            validRange = true
        }
    }

    if !validRange {
        fmt.Println("INVALID RANGE")
    }
}

func isNumberKaprekar(number uint64) bool {
    squareNumber := uint64(math.Pow(float64(number), float64(2)))
    divisor := uint64(math.Pow(float64(10), float64(numberDigits(number))))
    leftNumber, rightNumber := bits.Div64(0, squareNumber, divisor)
    return number == leftNumber+rightNumber
}

func numberDigits(n uint64) int {
    return len(strconv.Itoa(int(n)))
}
