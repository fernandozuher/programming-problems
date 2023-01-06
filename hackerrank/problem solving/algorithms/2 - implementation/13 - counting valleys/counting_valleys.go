// Source: https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

package main

import (
    "fmt"
    "unicode"
)

func main() {
    var n int = readLineAsInt()
    var steps []rune = readLineAsCharactersArray(n)

    var result int = countingValleys(steps)
    fmt.Print(result)
}

    func readLineAsInt() int {
        var inputLine int

        _, err := fmt.Scanf("%d", &inputLine)
        checkError(err)

        return inputLine
    }

    func readLineAsCharactersArray(n int) []rune {
        var inputLine []rune = make([]rune, n)

        for i := 0; i < n; i++ {
            inputLine[i] = readOneCharacterWihtouSpace()
        }

        return inputLine
    }

        func readOneCharacterWihtouSpace() rune {
            var character rune = ' ';

            for unicode.IsSpace(character) {
                _, err := fmt.Scanf("%c", &character)
                checkError(err)
            }

            return character
        }

            func checkError(err error) {
                if err != nil {
                    panic(err)
                }
            }

    func countingValleys(steps []rune) int {
        currentAltitude := 0
        traversedValleys := 0
        
        for _, step := range steps {
            var wasTravessingAValley bool = currentAltitude < 0

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
