// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    var array []int = read_int_array(n)
    fmt.Println(simple_array_sum(array))
}

    func read_int_array(n int) []int {
        array := make([]int, n)
        for i := 0; i < n; i++ {
            fmt.Scan(&array[i])
        }
        return array
    }

    func simple_array_sum(array []int) int {
        var sum int = 0
        for _, num := range array {
            sum += num
        }
        return sum
    }
