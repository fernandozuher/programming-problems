// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    var steps string
    _, _ = fmt.Scan(&steps)
    fmt.Println(countingValleys(steps))
}

// n: length of string steps
// T: O(n)
// S: O(1) extra space
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
