// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

package main

import (
    "fmt"
    "strings"
)

func main() {
    var n int
    fmt.Scan(&n)
    binary := intToBinary(n)
    fmt.Println(findSizeWidestRangeBits1From(binary))
}

func intToBinary(n int) string {
    return fmt.Sprintf("%b", n)
}

func findSizeWidestRangeBits1From(binary string) int {
    sizeWidestRange := 0
    for i := 0; i < len(binary); i++ {
        if binary[i] == '1' {
            binaryFromI := binary[i:]
            sizeRange := findSizeNextRangeBits1From(binaryFromI)
            sizeWidestRange = max(sizeRange, sizeWidestRange)
            i += sizeRange
        }
    }
    return sizeWidestRange
}

func findSizeNextRangeBits1From(binary string) int {
    if size := findBit0(binary); size != -1 {
        return size
    }
    return len(binary)
}

func findBit0(binary string) int {
    return strings.IndexRune(binary, '0')
}
