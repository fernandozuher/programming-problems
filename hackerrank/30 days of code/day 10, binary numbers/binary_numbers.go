// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)

    var maxOnes, ones int
    for ; n > 0; n /= 2 {
        if n%2 == 1 {
            ones++
        } else {
            if ones > maxOnes {
                maxOnes = ones
            }
            ones = 0
        }
    }

    if ones > maxOnes {
        maxOnes = ones
    }
    fmt.Println(maxOnes)
}
