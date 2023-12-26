// Source: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

package main

import "fmt"

func main() {
    const SIZE int = 4
    var array []int = readIntArray(SIZE)
    fmt.Println(kangaroo(array))
}

    func readIntArray(size int) []int {
        array := make([]int, size)
        for i := range array {
            fmt.Scan(&array[i])
        }
        return array
    }

    func kangaroo(array []int) string {
        var x1 int = array[0]
        var v1 int = array[1]
        var x2 int = array[2]
        var v2 int = array[3]

        if v2 >= v1 {
            return "NO"
        }

        for ; x1 < x2; x1, x2 = x1+v1, x2+v2 {
        }

        if x1 == x2 {
            return "YES"
        } else {
            return "NO"
        }
    }
