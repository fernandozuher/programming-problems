// https//www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    fmt.Println(equalizeArray(counter(n), n))
}

func counter(n int) map[int]int {
    count := make(map[int]int)
    for range n {
        var x int
        _, _ = fmt.Scan(&x)
        count[x]++
    }
    return count
}

func equalizeArray(counter map[int]int, n int) int {
    maxCount := 0
    for _, count := range counter {
        if count > maxCount {
            maxCount = count
        }
    }
    return n - maxCount
}
