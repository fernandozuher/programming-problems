// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    array := make([]int, n)

    for i := range array {
        fmt.Scanf("%d", &array[i])
    }

    array = reverseArray(array)

    for _, x := range array {
        fmt.Printf("%d ", x)
    }
}

    func reverseArray(array []int) []int {
        for i, j := 0, len(array)-1; i < j; i, j = i+1, j-1 {
            array[i], array[j] = array[j], array[i]
        }
        return array
    }
