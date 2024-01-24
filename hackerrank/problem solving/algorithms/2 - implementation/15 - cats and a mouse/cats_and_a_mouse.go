// https://www.hackerrank.com/challenges/cats-and-a-mouse/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    fmt.Scan(&n)
    nearestCatsOrNot := make([]string, n)

    for i, animals := 0, 3; i < n; i++ {
        var positions []int = readIntArray(animals)
        nearestCatsOrNot[i] = findNearestCatOrNot(positions)
    }

    for _, closestCatOrNot := range nearestCatsOrNot {
        fmt.Println(closestCatOrNot)
    }
}

    func readIntArray(n int) []int {
        array := make([]int, n)
        for i := range array {
            fmt.Scanf("%d", &array[i])
        }
        return array
    }

    func findNearestCatOrNot(catsAndMousePositions []int) string {
        var catAPosition int = catsAndMousePositions[0]
        var catBPosition int = catsAndMousePositions[1]
        var mousePosition int = catsAndMousePositions[2]

        var catAPositionFromMouse int = int(math.Abs(float64(catAPosition) - float64(mousePosition)))
        var catBPositionFromMouse int = int(math.Abs(float64(catBPosition) - float64(mousePosition)))

        if catAPositionFromMouse < catBPositionFromMouse {
            return "Cat A"
        } else if catAPositionFromMouse > catBPositionFromMouse {
            return "Cat B"
        } else {
            return "Mouse C"
        }
    }
