// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, k int
    fmt.Scan(&n, &k)
    numbers := readNumbers(n)
    fmt.Println(divisibleSumPairs(numbers, k))
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range numbers {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

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
    k := len(frequency)
    for i, n := 1, (k+1)/2; i < n; i++ {
        count += frequency[i] * frequency[k-i]
    }
    return count
}

func countPairsWithRemainderKHalf(frequency []int) int {
    k := len(frequency)
    if k%2 == 0 {
        return pairCount(frequency[k/2])
    }
    return 0
}
