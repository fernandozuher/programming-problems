// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    fmt.Println(simple_array_sum(n))
}

    func simpleArraySum(n int) int {
        var sum int = 0
        for i := range n {
            var x int
            fmt.Scan(&x)
            sum += x
        }
        return sum
    }
