// Source: https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)

    var chocolateSquares []int = readIntArray(n)

    const nDayMonth int = 2
    var dayMonth []int = readIntArray(nDayMonth)

    fmt.Print(birthday(chocolateSquares, dayMonth))
}

func readIntArray(n int) []int {
    array := make([]int, n)
    for i := range array {
        fmt.Scanf("%d", &array[i])
    }
    return array
}

func birthday(chocolateSquares []int, dayMonth []int) int {
    waysBarCanBeDivided := 0
    day := dayMonth[0]
    month := dayMonth[1]

    for i, n1 := 0, len(chocolateSquares)-month+1; i < n1; i++ {
        sum := 0
        for j, n2 := i, i+month; j < n2; j++ {
            sum += chocolateSquares[j]
        }

        if sum == day {
            waysBarCanBeDivided++
        }
    }

    return waysBarCanBeDivided
}
