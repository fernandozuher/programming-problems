// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    var array []int = readIntArray(n)
    fmt.Println(sockMerchant(array))
}

func readIntArray(n int) []int {
    array := make([]int, n)
    for i := range array {
        fmt.Scan(&array[i])
    }
    return array
}

func sockMerchant(socks []int) int {
    pairs := 0
    socksPairing := make(map[int]bool)

    for _, sock := range socks {
        if socksPairing[sock] {
            pairs++
        }
        socksPairing[sock] = !socksPairing[sock]
    }

    return pairs
}
