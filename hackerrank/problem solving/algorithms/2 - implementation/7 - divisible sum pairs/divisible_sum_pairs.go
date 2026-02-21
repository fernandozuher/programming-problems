// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, k int
    _, _ = fmt.Scan(&n, &k)
    numbers := readNumbers(n)
    fmt.Println(divisibleSumPairs(numbers, k))
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of array numbers
// k: length of array frequency
// T: O(n + k)
// S: O(k) extra space
func divisibleSumPairs(numbers []int, k int) int {
    frequency := initRemainderFrequency(numbers, k)
    return countPairsWithRemainder0(frequency) + countComplementaryRemainderPairs(frequency) + countPairsWithRemainderKHalf(frequency)
}

func initRemainderFrequency(numbers []int, k int) []int {
    frequency := make([]int, k)
    for _, x := range numbers {
        frequency[x%k]++
    }
    return frequency
}

func countPairsWithRemainder0(frequency []int) int {
    return pairCount(frequency[0])
}

func pairCount(n int) int {
    return n * (n - 1) / 2
}

func countComplementaryRemainderPairs(frequency []int) int {
    count := 0
    n := len(frequency)
    for i, n2 := 1, (n+1)/2; i < n2; i++ {
        count += frequency[i] * frequency[n-i]
    }
    return count
}

func countPairsWithRemainderKHalf(frequency []int) int {
    n := len(frequency)
    if n%2 == 0 {
        return pairCount(frequency[n/2])
    }
    return 0
}
