// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true
// From Go 1.22

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
        fmt.Scan(&array[i])
    }
    return array
}

func birthday(chocolateSquares []int, dayMonth []int) int {
    waysBarCanBeDivided := 0
    day := dayMonth[0]
    month := dayMonth[1]

    for i := range len(chocolateSquares) - month + 1 {
        sum := 0
        for j := range month {
            sum += chocolateSquares[j+i]
        }
        if sum == day {
            waysBarCanBeDivided++
        }
    }

    return waysBarCanBeDivided
}
