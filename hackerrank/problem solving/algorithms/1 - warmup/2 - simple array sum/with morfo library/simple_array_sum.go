// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
)

func main() {
    morfoio.SkipInputLn()
    fmt.Println(sumStdin())
}

// n: number of integers in the input line
// T: O(n)
// S: O(1) extra space
func sumStdin() int {
    sum := 0
    arr := morfoio.ReadLn[int]()
    for _, x := range arr {
        sum += x
    }
    return sum
}
