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

func calcMinMaxSum(numbers []int) (int, int) {
    sum, minValue, maxValue := numbers[0], numbers[0], numbers[0]

    for _, x := range numbers[1:] {
        sum += x
        minValue = min(x, minValue)
        maxValue = max(x, maxValue)
    }

    return sum - maxValue, sum - minValue
}
