// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

package main

import (
	"fmt"
	"morfo/morfoio"
	"slices"
)

func main() {
	nCities, nStations := morfoio.Read2[int, int]()
	lastCity := nCities - 1
	stations := morfoio.ReadN[int](nStations)
	slices.Sort(stations)
	fmt.Println(maxDistanceFromSpaceStation(lastCity, stations))
}

// n: length of stations
// T: O(n)
// S: O(1) extra space
func maxDistanceFromSpaceStation(lastCity int, stations []int) int {
	maxDist := stations[0]
	n := len(stations)

	for i := 1; i < n; i++ {
		gap := (stations[i] - stations[i-1]) / 2
		maxDist = max(maxDist, gap)
	}

	return max(maxDist, lastCity-stations[n-1])
}
