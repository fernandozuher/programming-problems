// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

// Fail in a few cases because TIME LIMIT exceeded

package main

import "fmt"

func main() {
    var n, nQueries int
    fmt.Scan(&n, &nQueries)
    fmt.Println(arrayManipulation(n, nQueries))
}

    func arrayManipulation(n int, nQueries int) int {
        array := make([]int, n + 2) // n + 2 = 1-indexed array + range-end)

        for b, e, summand := 0, 0, 0; nQueries > 0; nQueries-- {
            fmt.Scan(&b, &e, &summand)
            array[b] += summand
            array[e+1] -= summand
        }

        var sum, max int = 0, 0
        for _, x := range array {
            if x == 0 {
                continue
            }

            sum += x
            if sum > max {
                max = sum
            }
        }

        return max
    }
