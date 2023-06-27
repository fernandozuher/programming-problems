// Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

package main

import (
    "fmt"
    "sort"
)

func main() {
    var nCities, nCitiesWithSpaceStation int
    fmt.Scan(&nCities)
    fmt.Scan(&nCitiesWithSpaceStation)

    var citiesWithSpaceStation []int = readAnIntArray(nCitiesWithSpaceStation)
    fmt.Println(findMaxDistanceFromSpaceStation(nCities, citiesWithSpaceStation))
}

    func readAnIntArray(size int) []int {
        array := make([]int, size)
        for i := 0; i < size; i++ {
            fmt.Scan(&array[i])
        }
        return array
    }

    func findMaxDistanceFromSpaceStation(nCities int, citiesWithSpaceStation []int) int {
        sort.Ints(citiesWithSpaceStation)
        const firstCity int = 0
        var maxDistance int = citiesWithSpaceStation[0] - firstCity
        var size int = len(citiesWithSpaceStation)

        for i, previousCity := 1, citiesWithSpaceStation[0]; i < size; i++ {
            var distance int = calculateDistanceBetweenCities(citiesWithSpaceStation[i], previousCity)
            if maxDistance < distance {
                maxDistance = distance
            }
            previousCity = citiesWithSpaceStation[i]
        }

        var lastCity int = nCities - 1
        var lastCityWithSpaceStation int = citiesWithSpaceStation[size-1]
        if !hasLastCitySpaceStation(lastCity, lastCityWithSpaceStation) {
            var distance int = calculateDistanceOfLastCity(lastCity, lastCityWithSpaceStation)
            if maxDistance < distance {
                maxDistance = distance
            }
        }

        return maxDistance
    }

        func calculateDistanceBetweenCities(cityWithSpaceStation int, previousCity int) int {
            return (cityWithSpaceStation - previousCity) / 2
        }

        func hasLastCitySpaceStation(lastCity int, lastCityWithSpaceStation int) bool {
            return lastCity == lastCityWithSpaceStation
        }

        func calculateDistanceOfLastCity(lastCity int, lastCityWithSpaceStation int) int {
            return lastCity - lastCityWithSpaceStation
        }
