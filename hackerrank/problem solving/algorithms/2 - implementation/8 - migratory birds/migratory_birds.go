// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    birdCounts := counter(n)
    fmt.Println(findMostSpottedBird(birdCounts))
}

func counter(n int) map[int]int {
    numberCounts := map[int]int{}
    for range n {
        var x int
        fmt.Scan(&x)
        numberCounts[x]++
    }
    return numberCounts
}

func findMostSpottedBird(birdCounts map[int]int) int {
    mostSpottedBird := 0
    maxCount := 0
    for bird, count := range birdCounts {
        if count > maxCount || (count == maxCount && bird < mostSpottedBird) {
            mostSpottedBird = bird
            maxCount = count
        }
    }
    return mostSpottedBird
}
