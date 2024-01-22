// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    var array string
    fmt.Scan(&array)
    fmt.Println(countingValleys(array))
}

    func countingValleys(steps string) int {
        var currentAltitude int = 0
        var traversedValleys int = 0

        for _, step := range steps {
            wasTravessingAValley := currentAltitude < 0

            if step == 'D' {
                currentAltitude--
            } else {
                currentAltitude++
            }

            if isInSeaLevelFromValley(wasTravessingAValley, currentAltitude) {
                traversedValleys++
            }
        }

        return traversedValleys
    }

        func isInSeaLevelFromValley(wasTravessingAValley bool, currentAltitude int) bool {
            return wasTravessingAValley && currentAltitude == 0
        }
