// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

package main

import (
    "fmt"
    "slices"
)

func main() {
    var nWidths, nPoints int
    _, _ = fmt.Scan(&nWidths, &nPoints)
    widths := readNumbers(nWidths)
    for range nPoints {
        fmt.Println(maxAffordableWidthVehicleInRange(widths, readNumbers(2)))
    }
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

func maxAffordableWidthVehicleInRange(widths, point []int) int {
    start := point[0]
    finish := point[1]
    return slices.Min(widths[start : finish+1])
}
