// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

package main

import (
	"fmt"
	"morfo/morfocollections"
	"morfo/morfoio"
	"slices"
)

func main() {
	arr := morfoio.ReadLn[int]()
	minSum, maxSum := calcMinMaxSum(arr)
	fmt.Println(minSum, maxSum)
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
func calcMinMaxSum(arr []int) (int, int) {
	total, minValue, maxValue := morfocollections.ReduceMany3(slices.Values(arr),
		add, 0,
		smaller, arr[0],
		larger, arr[0],
	)

	return total - maxValue, total - minValue
}

func add(a, b int) int {
	return a + b
}

func smaller(a, b int) int {
	return min(a, b)
}

func larger(a, b int) int {
	return max(a, b)
}
