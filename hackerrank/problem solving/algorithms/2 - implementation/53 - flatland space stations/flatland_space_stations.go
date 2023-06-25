// Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
    "sort"
)

func main() {
    var nCities, nCitiesWithSpaceStation int
    fmt.Scan(&nCities)
    fmt.Scan(&nCitiesWithSpaceStation)

    var citiesWithSpaceStation []int = readAnIntArray(nCitiesWithSpaceStation)
    fmt.Println(findMaximumDistanceFromSpaceStation(nCities, citiesWithSpaceStation))
}

    func readAnIntArray(size int) []int {
        array := make([]int, size)
        for i := 0; i < size; i++ {
            fmt.Scan(&array[i])
        }
        return array
    }

    func findMaximumDistanceFromSpaceStation(nCities int, citiesWithSpaceStation []int) int {
        var maxDistance int = 0

        sort.Ints(citiesWithSpaceStation)

        for cityI := 0; cityI < nCities; cityI++ {
            var distance int = findMinDistanceBetweenCityAndNearestSpaceStation(cityI, citiesWithSpaceStation)
            if maxDistance < distance {
                maxDistance = distance
            }
        }

        return maxDistance
    }

        func findMinDistanceBetweenCityAndNearestSpaceStation(cityI int, citiesWithSpaceStation []int) int {
            var element int = findElementOrNearest(cityI, citiesWithSpaceStation)
            var minDistanceBetweenCityAndNearestSpaceStation int = int(math.Abs(float64(cityI - element)))
            return minDistanceBetweenCityAndNearestSpaceStation
        }

            func findElementOrNearest(n int, array []int) int {
                var max int = len(array) - 1
                var min int = 0

                var minDistance int = math.MaxInt32
                var nearestElement int = n

                for min <= max {
                    var mid int = int(math.Trunc(float64((min + max) / 2)))

                    var distance int = int(math.Abs(float64(array[mid] - n)))
                    if distance < minDistance {
                        nearestElement = array[mid]
                        minDistance = distance
                    }

                    if array[mid] == n {
                        return n
                    } else if array[mid] > n {
                        max = mid - 1
                    } else {
                        min = mid + 1
                    }
                }

                return nearestElement
            }
