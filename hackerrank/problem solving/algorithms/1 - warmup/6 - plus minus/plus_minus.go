// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true
// From Go 1.22

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    positiveProportion, negativeProportion, zeroProportion := plusMinus(n)
    fmt.Printf("%.6f\n", positiveProportion)
    fmt.Printf("%.6f\n", negativeProportion)
    fmt.Printf("%.6f", zeroProportion)
}

func plusMinus(n int) (float64, float64, float64) {
    positive, negative, zero := 0, 0, 0

    for range n {
        var x int
        fmt.Scan(&x)
        if x > 0 {
            positive++
        } else if x < 0 {
            negative++
        } else {
            zero++
        }
    }

    positiveProportion := float64(positive) / float64(n)
    negativeProportion := float64(negative) / float64(n)
    zeroProportion := float64(zero) / float64(n)

    return positiveProportion, negativeProportion, zeroProportion
}
