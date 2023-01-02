// Source: https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=truehttps://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    birdSightings := readNumberStepByStepAndPutIntoIntArray(scanner)

    sort.Ints(birdSightings)

    result := migratoryBirds(birdSightings)
    fmt.Println(result)
}

    func readNumberStepByStepAndPutIntoIntArray(scanner *bufio.Scanner) []int {
        var n int
        _, err := fmt.Scan(&n)
        checkError(err)

        numbers := make([]int, n)
        
        for i, _ := range numbers {
            _, err := fmt.Scan(&numbers[i])
            checkError(err)
        }
        
        return numbers
    }

        func checkError(err error) {
            if err != nil {
                panic(err)
            }
        }

    func migratoryBirds(birdSightings []int) int {
        mostSpottedBird := birdSightings[0]
        countMostSpottedBird := 1
        tempCountMostSpottedBird := 1

        n := len(birdSightings)
        for i := 1; i < n; i++ {

            if birdSightings[i] == birdSightings[i - 1] {
                tempCountMostSpottedBird++
            } else if tempCountMostSpottedBird > countMostSpottedBird {
                mostSpottedBird = birdSightings[i - 1]
                countMostSpottedBird = tempCountMostSpottedBird
                tempCountMostSpottedBird = 1
            }
        }

        if tempCountMostSpottedBird > countMostSpottedBird {
            mostSpottedBird = birdSightings[n - 1]
        }

        return mostSpottedBird
    }
