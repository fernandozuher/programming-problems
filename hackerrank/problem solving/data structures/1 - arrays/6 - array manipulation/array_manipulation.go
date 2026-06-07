// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, nQueries int
    _, _ = fmt.Scan(&n, &nQueries)
    fmt.Println(arrayManipulation(n, nQueries))
}

// T: O(n + nQueries)
// S: O(n) extra space
func arrayManipulation(n, nQueries int) int {
    arr := populateArr(n, nQueries)
    return maxSequentialSum(arr)
}

func populateArr(n, nQueries int) []int {
    arr := make([]int, n+2) // +2 = 1-indexed array + range-end)

    for range nQueries {
        var b, e, summand int
        _, _ = fmt.Scan(&b, &e, &summand)
        arr[b] += summand
        arr[e+1] -= summand
    }

    return arr
}

func maxSequentialSum(arr []int) int {
    sum, maxSum := 0, 0
    for _, x := range arr {
        sum += x
        maxSum = max(maxSum, sum)
    }
    return maxSum
}
