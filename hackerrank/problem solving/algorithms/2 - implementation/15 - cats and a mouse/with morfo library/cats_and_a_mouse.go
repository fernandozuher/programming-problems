// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true

package main

import (
	"fmt"
	"morfo/morfoio"
	"morfo/morfomath"
)

func main() {
	n := morfoio.Read[int]()
	for range n {
		fmt.Println(findNearestCatOrNot(morfoio.ReadLn[int]()))
	}
}

// T: O(1)
// S: O(1) extra space
func findNearestCatOrNot(positions []int) string {
	catA, catB, mouse := positions[0], positions[1], positions[2]
	catAFromMouse := morfomath.Abs(catA - mouse)
	catBFromMouse := morfomath.Abs(catB - mouse)

	if catAFromMouse < catBFromMouse {
		return "Cat A"
	}
	if catAFromMouse > catBFromMouse {
		return "Cat B"
	}
	return "Mouse C"
}
