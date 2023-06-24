// Source: https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    var nWidthMeasurements, nTestCases int
    fmt.Scan(&nWidthMeasurements, &nTestCases)
    var widthMeasurements []int = readAnIntArray(nWidthMeasurements)

    var maximumAffordableWidthsVehicles []int = findMaximumAffordableWidthsVehiclesWhileReadTestCases(nTestCases, widthMeasurements)
    for _, element := range maximumAffordableWidthsVehicles {
        fmt.Println(element)
    }
}

    func readAnIntArray(size int) []int {
        array := make([]int, size)
        for i, _ := range array {
            fmt.Scan(&array[i])
        }
        return array
    }

    func findMaximumAffordableWidthsVehiclesWhileReadTestCases(nTestCases int, widthMeasurements []int) []int {
        maximumAffordableWidthsVehicles := make([]int, nTestCases)
        const TEST_CASE_SIZE = 2

        for i , _ := range maximumAffordableWidthsVehicles {
            maximumAffordableWidthsVehicles[i] = maximumAffordableWidthVehicleInRange(widthMeasurements, readAnIntArray(TEST_CASE_SIZE))
        }

        return maximumAffordableWidthsVehicles
    }

        func maximumAffordableWidthVehicleInRange(widthMeasurements []int, point []int) int {
            var min int = math.MaxInt
            for i := point[0]; i <= point[1]; i++ {
                min = int(math.Min(float64(min), float64(widthMeasurements[i])))
            }
            return min
        }
