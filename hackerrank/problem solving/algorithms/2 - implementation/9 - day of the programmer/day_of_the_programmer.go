// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

package main

import (
    "fmt"
    "strconv"
)

const transitionYear = 1918

func main() {
    var year int
    _, _ = fmt.Scan(&year)
    fmt.Println(calculateDateOf256thDay(year))
}

func calculateDateOf256thDay(year int) string {
    var day string
    if year == transitionYear {
        day = "26"
    } else if isLeapYear(year) {
        day = "12"
    } else {
        day = "13"
    }
    return day + ".09." + strconv.Itoa(year)
}

func isLeapYear(year int) bool {
    if year < transitionYear {
        return isLeapJulianYear(year)
    }
    if year > transitionYear {
        return isLeapGregorianYear(year)
    }
    return false
}

func isLeapJulianYear(year int) bool {
    return year%4 == 0
}

func isLeapGregorianYear(year int) bool {
    return year%400 == 0 || (year%4 == 0 && year%100 != 0)
}
