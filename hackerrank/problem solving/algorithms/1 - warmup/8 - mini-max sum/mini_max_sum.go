// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

package main

import "fmt"

func main() {
    const n = 5
    var numbers []int = readNumbers(n)
    var minSum, maxSum int = calcMinMaxSum(numbers)
    fmt.Println(minSum, maxSum)
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range numbers {
        fmt.Scan(&numbers[i])
    }
    return numbers
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
