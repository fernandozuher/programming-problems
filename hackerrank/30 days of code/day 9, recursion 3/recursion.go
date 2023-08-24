// https://www.hackerrank.com/challenges/30-recursion/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    fmt.Println(factorial(n))
}

    func factorial(n int) int {
        if n == 1 {
            return 1
        }
        return n * factorial(n-1)
    }
