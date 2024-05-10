// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

package main

import (
    "fmt"
    "slices"
)

func main() {
    var nWidthMeasurements, n int
    fmt.Scan(&nWidthMeasurements, &n)
    for _, x := range findMaximumAffordableWidthsVehiclesWhileReadTestCases(n, readIntArray(nWidthMeasurements)) {
        fmt.Println(x)
    }
}

func readIntArray(n int) []int {
    array := make([]int, n)
    for i := range array {
        fmt.Scan(&array[i])
    }
    return array
}

func findMaximumAffordableWidthsVehiclesWhileReadTestCases(n int, widthMeasurements []int) []int {
    maximumAffordableWidthsVehicles := make([]int, n)
    const TestCaseSize = 2
    for i := range maximumAffordableWidthsVehicles {
        maximumAffordableWidthsVehicles[i] = maximumAffordableWidthVehicleInRange(widthMeasurements, readIntArray(TestCaseSize))
    }
    return maximumAffordableWidthsVehicles
}

func maximumAffordableWidthVehicleInRange(widthMeasurements []int, point []int) int {
    return slices.Min(widthMeasurements[point[0] : point[1]+1])
}
