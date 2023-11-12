// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var size int = 3
    var array1 []int = readAnIntArray(size)
    var array2 []int = readAnIntArray(size)
    var result []int = compareTriplets(array1, array2)
    fmt.Printf("%d %d\n", result[0], result[1])
}

    func readAnIntArray(size int) []int {
        array := make([]int, size)
        for i, _ := range array {
            fmt.Scan(&array[i])
        }
        return array
    }

    func compareTriplets(a []int, b []int) []int {

        var player1, player2 int = 0, 0

        for i := range a {
            if a[i] > b[i] {
                player1++
            } else if a[i] < b[i] {
                player2++
            }
        }

        return []int{player1, player2}
    }
