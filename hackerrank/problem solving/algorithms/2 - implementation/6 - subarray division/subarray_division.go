// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var n int
    _, _ = fmt.Scan(&n)
    chocolateSquares := readNumbers(n)
    const nDayMonth int = 2
    dayMonth := readNumbers(nDayMonth)
    fmt.Println(birthday(chocolateSquares, dayMonth))
}

func readNumbers(n int) []int {
    arr := make([]int, n)
    for i := range arr {
        _, _ = fmt.Scan(&arr[i])
    }
    return arr
}

func birthday(chocolateSquares []int, dayMonth []int) int {
    day := dayMonth[0]
    month := dayMonth[1]

    if month > len(chocolateSquares) {
        return 0
    }

    sum := 0
    for _, x := range chocolateSquares[:month] {
        sum += x
    }

    waysBarCanBeDivided := 0
    if sum == day {
        waysBarCanBeDivided++
    }

    for i := month; i < len(chocolateSquares); i++ {
        sum += chocolateSquares[i] - chocolateSquares[i-month]
        if sum == day {
            waysBarCanBeDivided++
        }
    }

    return waysBarCanBeDivided
}
