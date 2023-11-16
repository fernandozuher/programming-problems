// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)

    array := make([]int64, n)
    for i := range array {
        fmt.Scan(&array[i])
    }

    fmt.Println(aVeryBigSum(array))
}

func aVeryBigSum(array []int64) int64 {
    var sum int64 = 0
    for _, number := range array {
        sum += number
    }
    return sum
}
