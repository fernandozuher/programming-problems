// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    sockCounts := readNumbersIntoMap(n)
    fmt.Println(sockMerchant(sockCounts))
}

func readNumbersIntoMap(n int) map[int]int {
    numberCounts := map[int]int{}
    for range n {
        var x int
        fmt.Scan(&x)
        numberCounts[x]++
    }
    return numberCounts
}

func sockMerchant(sockCounts map[int]int) int {
    pairs := 0
    for _, n := range sockCounts {
        pairs += n / 2
    }
    return pairs
}
