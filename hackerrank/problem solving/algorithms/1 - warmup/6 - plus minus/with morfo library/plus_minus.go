// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

package main

import (
	"fmt"
	"morfo/morfocollections"
	"morfo/morfoio"
)

func main() {
	morfoio.SkipInputLn()
	arr := morfoio.ReadLn[int]()
	ratios := plusMinus(arr)
	printRatios(ratios)
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
func plusMinus(arr []int) []float64 {
	positive := morfocollections.CountFunc(arr, func(number int) bool { return number > 0 })
	negative := morfocollections.CountFunc(arr, func(number int) bool { return number < 0 })
	zero := morfocollections.Count(arr, 0)

	n := float64(len(arr))
	positiveRatio := float64(positive) / n
	negativeRatio := float64(negative) / n
	zeroRatio := float64(zero) / n

	return []float64{positiveRatio, negativeRatio, zeroRatio}
}

func printRatios(ratios []float64) {
	for _, ratio := range ratios {
		fmt.Printf("%.6f\n", ratio)
	}
}
