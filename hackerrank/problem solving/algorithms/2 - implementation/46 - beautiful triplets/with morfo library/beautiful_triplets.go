// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

package main

import (
	"fmt"
	"morfo/morfocollections"
	"morfo/morfoio"
)

func main() {
	morfoio.SkipInput()
	beautifulDifference := morfoio.Read[int]()
	arr := morfoio.ReadLn[int]()
	fmt.Println(findBeautifulTriplets(arr, beautifulDifference))
}

// n: length of arr
// k: distinct numbers of arr
// k <= n
// T: O(n)
// S: O(k) = O(n) extra space
func findBeautifulTriplets(arr []int, beautifulDifference int) int {
	values := make(map[int]bool)
	for _, v := range arr {
		values[v] = true
	}

	doubleBD := 2 * beautifulDifference
	return morfocollections.CountFunc(arr, func(x int) bool {
		return values[x+beautifulDifference] && values[x+doubleBD]
	})
}
