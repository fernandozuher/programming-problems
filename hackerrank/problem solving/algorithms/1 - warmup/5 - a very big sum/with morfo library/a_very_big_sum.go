// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

package main

import (
    "fmt"
    "morfo/morfoio"
    "morfo/morfomath"
)

func main() {
    morfoio.SkipInputLn()
    arr := morfoio.ReadLn[int64]()
    fmt.Println(aVeryBigSum(arr))
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
func aVeryBigSum(arr []int64) int64 {
    return morfomath.Sum(arr)
}
