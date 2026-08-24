// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

package main

import (
	"fmt"
	"morfo/morfocollections"
	"morfo/morfoio"
)

func main() {
	n := morfoio.Read[int]()

	for range n {
		morfoio.SkipInput()
		threshold := morfoio.Read[int]()
		arrivalTimes := morfoio.ReadLn[int]()

		if angryProfessor(arrivalTimes, threshold) {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

// k: length of arrivalTimes
// T: O(k)
// S: O(1) extra space
func angryProfessor(arrivalTimes []int, threshold int) bool {
	onTime := morfocollections.CountFunc(arrivalTimes, func(t int) bool { return t <= 0 })
	return onTime < threshold
}
