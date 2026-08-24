// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

package main

import (
	"fmt"
	"morfo/morfoio"
)

func main() {
	n, k := morfoio.Read2[int, int]()
	numbers := morfoio.ReadN[int](n)
	fmt.Println(divisibleSumPairs(numbers, k))
}

// n: length of numbers
// k: length of freq
// T: O(n + k)
// S: O(k) extra space
func divisibleSumPairs(numbers []int, k int) int {
	freq := initRemainderFrequency(numbers, k)
	return countPairsWithRemainder0(freq) + countComplementaryRemainderPairs(freq) + countPairsWithRemainderKHalf(freq)
}

func initRemainderFrequency(numbers []int, k int) []int {
	freq := make([]int, k)
	for _, x := range numbers {
		freq[x%k]++
	}
	return freq
}

func countPairsWithRemainder0(freq []int) int {
	return pairCount(freq[0])
}

func pairCount(n int) int {
	return n * (n - 1) / 2
}

func countComplementaryRemainderPairs(freq []int) int {
	count := 0
	n := len(freq)
	for i, n2 := 1, (n+1)/2; i < n2; i++ {
		count += freq[i] * freq[n-i]
	}
	return count
}

func countPairsWithRemainderKHalf(freq []int) int {
	n := len(freq)
	if n%2 == 0 {
		return pairCount(freq[n/2])
	}
	return 0
}
