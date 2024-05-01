// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
    "math/bits"
)

func main() {
    var lowerLimit, upperLimit uint64
    _, err := fmt.Scan(&lowerLimit, &upperLimit)
    if err != nil {
        return
    }

    validRange := false
    for number := range upperLimit + 1 { // from 1.22
        number += lowerLimit
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

        func numberDigits(n uint64) uint64 {
            if n < 10 {
                return 1
            } else if n < 100 {
                return 2
            } else if n < 1000 {
                return 3
            } else if n < 10000 {
                return 4
            } else if n < 100000 {
                return 5
            } else if n < 1000000 {
                return 6
            } else if n < 10000000 {
                return 7
            }
            return 8
        }
