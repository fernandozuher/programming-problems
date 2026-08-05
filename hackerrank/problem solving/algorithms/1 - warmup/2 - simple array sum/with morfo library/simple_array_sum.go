// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
    "morfo/morfomath"
)

func main() {
    morfoio.SkipInputLn()
    fmt.Println(sumStdin())
}

// n: number of integers in the input line
// T: O(n)
// S: O(n) extra space
func sumStdin() int {
    return morfomath.Sum(morfoio.ReadLn[int]())
}
