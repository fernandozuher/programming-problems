// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

package main

import (
    "fmt"
    "strings"
)

func main() {
    var n int
    fmt.Scan(&n)
    binary := fmt.Sprintf("%b", n)
    fmt.Println(findMaxLengthOfOnes(binary))
}

func findMaxLengthOfOnes(binary string) int {
    maxLength := 0
    for _, segment := range strings.Split(binary, "0") {
        maxLength = max(maxLength, len(segment))
    }
    return maxLength
}
