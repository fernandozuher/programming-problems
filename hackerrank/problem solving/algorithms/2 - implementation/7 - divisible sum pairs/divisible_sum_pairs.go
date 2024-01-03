// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=truehttps://www.hackerrank.com/challenges/the-divisibleSumPairs-bar/problem?isFullScreen=true

package main

import (
    "fmt"
    "sort"
)

func main() {
    var n, k int
    fmt.Scan(&n, &k)
    var array []int = readIntArray(n)

    sort.Ints(array)

    fmt.Print(divisibleSumPairs(array, k))
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func divisibleSumPairs(array []int, k int) int {
        var nDivisibleSumPairs int = 0

        for i, n2 := 0, len(array)-1; i < n2; i++ {
            for j, n := i+1, len(array); j < n; j++ {
                if array[i] <= array[j] && ((array[i]+array[j])%k == 0) {
                    nDivisibleSumPairs++
                }
            }
        }

        return nDivisibleSumPairs
    }
