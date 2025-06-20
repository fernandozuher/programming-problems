// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    birds := readNumbers(n)
    fmt.Println(findMostSpottedBird(birds))
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range numbers {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func findMostSpottedBird(birds []int) int {
    birdCount := map[int]int{}
    for _, bird := range birds {
        birdCount[bird]++
    }

    mostSpottedBird := 0
    maxCount := 0
    for bird, count := range birdCount {
        if count > maxCount || (count == maxCount && bird < mostSpottedBird) {
            mostSpottedBird = bird
            maxCount = count
        }
    }

    return mostSpottedBird
}
