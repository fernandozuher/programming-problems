// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

package main

import (
	"fmt"
	"morfo/morfoio"
	"morfo/morfomath"
)

func main() {
	morfoio.SkipInputLn()
	a := morfoio.ReadLn[int]()
	b := morfoio.ReadLn[int]()
	fmt.Println(betweenTwoSets(a, b))
}

// n1, n2: length of a, b
// k: number of multiples tested = gcdOfB / lcmOfA
// T: O(n1 + n2 + k)
// S: O(1) extra space
func betweenTwoSets(a, b []int) int {
	lcmOfA := morfomath.Lcm(a)
	gcdOfB := morfomath.Gcd(b)

	count := 0
	for i := lcmOfA; i <= gcdOfB; i += lcmOfA {
		if gcdOfB%i == 0 {
			count++
		}
	}
	return count
}
