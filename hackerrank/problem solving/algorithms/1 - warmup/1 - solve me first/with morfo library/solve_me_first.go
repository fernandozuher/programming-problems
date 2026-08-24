// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

package main

import (
	"fmt"
	"morfo/morfoio"
)

func main() {
	n1, n2 := morfoio.Read2[int, int]()
	fmt.Println(solveMeFirst(n1, n2))
}

// T: O(1)
// S: O(1) extra space
func solveMeFirst(n1, n2 int) int {
	return n1 + n2
}
