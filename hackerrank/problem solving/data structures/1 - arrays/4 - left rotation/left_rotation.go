// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n, rotateBy int
    fmt.Scan(&n, &rotateBy)
    var array []int = readIntArray(n)

    if rotateBy > n-1 {
        rotateBy %= n
    }

    array = rotate(array, rotateBy)
    printArray(array)
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func rotate(array []int, n int) []int {
        return append(array[n:], array[:n]...)
    }

    func printArray(array []int) {
        for _, x := range array {
            fmt.Printf("%d ", x)
        }
    }
