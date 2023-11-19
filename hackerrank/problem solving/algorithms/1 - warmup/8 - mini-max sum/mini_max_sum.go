// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

package main

import (
    "fmt"
    "sort"
)

func main() {
    const n int = 5
    var array []int = readIntArray(n)
    sort.Ints(array)
    miniMaxSum(array)
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            fmt.Scan(&array[i])
        }
        return array
    }

    func miniMaxSum(array []int) {
        var totalSum int = 0
        for _, value := range array {
            totalSum += value
        }

        var minSum int = totalSum - array[len(array)-1]
        var maxSum int = totalSum - array[0]
        fmt.Printf("%d %d", minSum, maxSum)
    }
