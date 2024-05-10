// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
    "sort"
)

func main() {
    var nCities, nCitiesWithSpaceStation int
    fmt.Scan(&nCities, &nCitiesWithSpaceStation)
    var citiesWithSpaceStation []int = readIntArray(nCitiesWithSpaceStation)
    sort.Ints(citiesWithSpaceStation)
    fmt.Println(findMaxDistanceFromSpaceStation(nCities, citiesWithSpaceStation))
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := 0; i < n; i++ {
            fmt.Scan(&array[i])
        }
        return array
    }

    func findMaxDistanceFromSpaceStation(nCities int, citiesWithSpaceStation []int) int {
        var maxDistance int = citiesWithSpaceStation[0]
        n := len(citiesWithSpaceStation)

        for i, previousCity := 1, citiesWithSpaceStation[0]; i < n; i++ {
            var distanceBetweenCities int = (citiesWithSpaceStation[i] - previousCity) / 2
            maxDistance = int(math.Max(float64(maxDistance), float64(distanceBetweenCities)))
            previousCity = citiesWithSpaceStation[i]
        }

        var lastCity int = nCities - 1
        var lastCityWithSpaceStation int = citiesWithSpaceStation[n-1]
        if hasLastCitySpaceStation := lastCity == lastCityWithSpaceStation; !hasLastCitySpaceStation {
            var distanceOfLastCity int = lastCity - lastCityWithSpaceStation
            maxDistance = int(math.Max(float64(maxDistance), float64(distanceOfLastCity)))
        }

        return maxDistance
    }
