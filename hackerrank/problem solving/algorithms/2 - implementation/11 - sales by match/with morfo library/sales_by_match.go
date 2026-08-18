// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

package main

import (
	"fmt"
	"morfo/morfocollections"
	"morfo/morfoio"
)

func main() {
	morfoio.SkipInputLn()
	socksToCounts := morfocollections.Counter(morfoio.ReadLn[int]())
	fmt.Println(sockMerchant(socksToCounts))
}

// k: length of entries in socksToCounts
// T: O(k)
// S: O(1) extra space
func sockMerchant(socksToCounts map[int]int) int {
	pairs := 0
	for _, x := range socksToCounts {
		pairs += x / 2
	}
	return pairs
}
