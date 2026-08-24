// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

package main

import (
	"fmt"
	"morfo/morfoio"
)

type State struct {
	x1, v1, x2, v2 int
}

func main() {
	initialState := readInput()
	if kangaroo(initialState) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func readInput() State {
	x1, v1, x2, v2 := morfoio.Read4[int, int, int, int]()
	return State{x1, v1, x2, v2}
}

// T: O(1)
// S: O(1) extra space
func kangaroo(s State) bool {
	if s.v1 == s.v2 {
		return s.x1 == s.x2
	}

	distanceDiff := s.x2 - s.x1
	velocityDiff := s.v1 - s.v2
	return distanceDiff*velocityDiff >= 0 && distanceDiff%velocityDiff == 0
}
