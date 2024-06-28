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
        fmt.Scan(&array[i])
    }
    return array
}

func divisibleSumPairs(array []int, k int) int {
    nDivisibleSumPairs := 0

    for i, num1 := range array[:len(array)-1] {
        for _, num2 := range array[i+1:] {
            if num1 <= num2 && ((num1+num2)%k == 0) {
                nDivisibleSumPairs++
            }
        }
    }

    return nDivisibleSumPairs
}
