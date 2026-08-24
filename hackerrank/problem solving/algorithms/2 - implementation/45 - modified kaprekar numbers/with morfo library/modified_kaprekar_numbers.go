// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

package main

import (
	"fmt"
	"math"
	"math/bits"
	"morfo/morfoio"
)

func main() {
	lower, upper := morfoio.Read2[uint64, uint64]()

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

// log n: for calculating number of digits
// T: O(log n)
// S: O(1) extra space
func isNumberKaprekar(n uint64) bool {
	squareNumber := uint64(math.Pow(float64(n), 2.0))
	divisor := uint64(math.Pow(10.0, float64(numberDigits(n))))
	leftNumber, rightNumber := bits.Div64(0, squareNumber, divisor)
	return n == leftNumber+rightNumber
}

func numberDigits(n uint64) int {
	return int(math.Log10(float64(n)) + 1)
}
