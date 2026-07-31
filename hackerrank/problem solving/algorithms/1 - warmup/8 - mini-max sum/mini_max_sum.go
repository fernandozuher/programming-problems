// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

package main

import "fmt"

func main() {
    const n = 5
    arr := readNums(n)
    minSum, maxSum := calcMinMaxSum(arr)
    fmt.Println(minSum, maxSum)
}

func readNums(n int) []int {
    arr := make([]int, n)
    for i := range arr {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
func calcMinMaxSum(arr []int) (int, int) {
    total, minValue, maxValue := arr[0], arr[0], arr[0]

    for _, x := range arr[1:] {
        total += x
        minValue = min(x, minValue)
        maxValue = max(x, maxValue)
    }

    return total - maxValue, total - minValue
}
