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
    fmt.Println(maxConsecutiveOnesFrom(binary))
}

func maxConsecutiveOnesFrom(binary string) int {
    maxNBits := 0
    for i := 0; i < len(binary); i++ {
        if binary[i] == '1' {
            nBits := sizeOfNextRangeOfBits1(binary, i)
            maxNBits = max(nBits, maxNBits)
            i += nBits
        }
    }
    return maxNBits
}

func sizeOfNextRangeOfBits1(binary string, beginIndex int) int {
    nextAfterLastIndex := findNextAfterLastIndexOfConsecutive1s(binary, beginIndex)
    return nextAfterLastIndex - beginIndex
}

func findNextAfterLastIndexOfConsecutive1s(binary string, beginIndex int) int {
    nextAfterLastIndex := strings.IndexRune(binary[beginIndex:], '0')
    if nextAfterLastIndex == -1 {
        return len(binary)
    }
    // + beginIndex because index was found from that, not from index 0
    return nextAfterLastIndex + beginIndex
}
