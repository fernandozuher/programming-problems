// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true&is_full_screen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    fmt.Scan(&n)
    nearestCatOrNot := make([]string, n)
    for i := range nearestCatOrNot {
        nearestCatOrNot[i] = findNearestCatOrNot(readNumbers(3))
    }
    for _, x := range nearestCatOrNot {
        fmt.Println(x)
    }
}

func readNumbers(n int) []int {
    numbers := make([]int, n)
    for i := range numbers {
        fmt.Scan(&numbers[i])
    }
    return numbers
}

func findNearestCatOrNot(positions []int) string {
    catA, catB, mouse := positions[0], positions[1], positions[2]
    catAFromMouse := math.Abs(float64(catA - mouse))
    catBFromMouse := math.Abs(float64(catB - mouse))

    if catAFromMouse < catBFromMouse {
        return "Cat A"
    }
    if catAFromMouse > catBFromMouse {
        return "Cat B"
    }
    return "Mouse C"
}
