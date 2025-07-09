// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    var steps string
    fmt.Scan(&steps)
    fmt.Println(countingValleys(steps))
}

func countingValleys(steps string) int {
    valleys := 0
    currentAltitude := 0

    for _, step := range steps {
        wasBelowSeaLevel := currentAltitude < 0
        if step == 'D' {
            currentAltitude--
        } else {
            currentAltitude++
        }
        if isInSeaLevelFromValley := wasBelowSeaLevel && currentAltitude == 0; isInSeaLevelFromValley {
            valleys++
        }
    }

    return valleys
}
