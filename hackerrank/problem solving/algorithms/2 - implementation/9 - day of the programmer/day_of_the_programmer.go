// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

package main

import (
    "fmt"
    "strconv"
)

const TransitionYear int = 1918

func main() {
    var year int
    fmt.Scan(&year)
    fmt.Print(calculateDateOf256thDay(year))
}

func calculateDateOf256thDay(year int) string {
    var date string
    if year != TransitionYear {
        if isLeapYear(year) {
            date = "12.09."
        } else {
            date = "13.09."
        }
    } else {
        date = "26.09."
    }
    date += strconv.Itoa(year)
    return date
}

func isLeapYear(year int) bool {
    if year > TransitionYear {
        return isLeapGregorianYear(year)
    } else {
        return isLeapJulianYear(year)
    }
}

func isLeapGregorianYear(year int) bool {
    return year%400 == 0 || (year%4 == 0 && year%100 != 0)
}

func isLeapJulianYear(year int) bool {
    return year%4 == 0
}
