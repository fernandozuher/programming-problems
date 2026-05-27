// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

package main

import "fmt"

func main() {
    const n = 5
    minSum, maxSum := calcMinMaxSum(readNumbers(n))
    fmt.Println(minSum, maxSum)
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
func calcMinMaxSum(arr []int) (int, int) {
    sum, minValue, maxValue := arr[0], arr[0], arr[0]

    for _, x := range arr[1:] {
        sum += x
        minValue = min(x, minValue)
        maxValue = max(x, maxValue)
    }

    return sum - maxValue, sum - minValue
}
