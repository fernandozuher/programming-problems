// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

package main

import (
	"fmt"
	"morfo/morfoio"
)

func main() {
	n := morfoio.Read[int]()
	for range n {
		prisoners, sweets, startChair := morfoio.Read3[int, int, int]()
		fmt.Println(saveThePrisoner(prisoners, sweets, startChair))
	}
}

// T: O(1)
// S: O(1) extra space
func saveThePrisoner(prisoners, sweets, startChair int) int {
	return ((startChair - 1 + sweets - 1) % prisoners) + 1
}
