// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

package main

import (
    "fmt"
    "slices"
)

func main() {
    var nCities, nStations int
    _, _ = fmt.Scan(&nCities, &nStations)
    stations := readNumbers(nStations)
    slices.Sort(stations)
    fmt.Println(maxDistanceFromSpaceStation(nCities, stations))
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range n {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

func maxDistanceFromSpaceStation(nCities int, stations []int) int {
    maxDist := stations[0]

    for i := 1; i < len(stations); i++ {
        gap := (stations[i] - stations[i-1]) / 2
        maxDist = max(maxDist, gap)
    }

    lastCity := nCities - 1
    return max(maxDist, lastCity - stations[len(stations)-1])
}
