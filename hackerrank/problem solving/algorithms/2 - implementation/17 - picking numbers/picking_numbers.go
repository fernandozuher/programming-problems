// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    fmt.Println(pickingNumbers(readNumbersIntoMap(n)))
}

func readNumbersIntoMap(n int) map[int]int {
    counter := make(map[int]int)
    for range n {
        var x int
        fmt.Scan(&x)
        counter[x]++
    }
    return counter
}

func pickingNumbers(counter map[int]int) int {
    maxLen := 0
    for num, count := range counter {
        maxLen = max(maxLen, count + counter[num+1])
    }
    return maxLen
}
