// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    for fmt.Scan(&n); n > 0; n-- {
        var number int
        fmt.Scan(&number)

        if number == 1 {
            fmt.Println("Not prime")
            continue
        }

        i, limit := 2, int(math.Sqrt(float64(number)))
        for ; i <= limit; i++ {
            if number%i == 0 {
                fmt.Println("Not prime")
                break
            }
        }

        if i > limit {
            fmt.Println("Prime")
        }
    }
}
