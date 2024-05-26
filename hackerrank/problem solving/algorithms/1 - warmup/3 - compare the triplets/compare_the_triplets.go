// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

package main

import "fmt"

func main() {
    const n = 3
    var array1 []int = readIntArray(n)
    var array2 []int = readIntArray(n)
    var result []int = compareTriplets(array1, array2)
    fmt.Printf("%d %d\n", result[0], result[1])
}

func readIntArray(n int) []int {
    array := make([]int, n)
    for i := range array {
        fmt.Scan(&array[i])
    }
    return array
}

func compareTriplets(a []int, b []int) []int {
    player1, player2 := 0, 0
    for i := range a {
        if a[i] > b[i] {
            player1++
        } else if b[i] > a[i] {
            player2++
        }
    }
    return []int{player1, player2}
}
