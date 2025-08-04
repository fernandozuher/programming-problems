// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var startDay, endDay, divisor int
    fmt.Scan(&startDay, &endDay, &divisor)
    fmt.Println(beautifulDays(startDay, endDay, divisor))
}

func beautifulDays(startDay, endDay, divisor int) int {
    count := 0
    for day := startDay; day <= endDay; day++ {
        if isDayBeautiful(day, divisor) {
            count++
        }
    }
    return count
}

func isDayBeautiful(day, divisor int) bool {
    n := day - reverseNumber(day)
    if n < 0 {
        n = -n
    }
    return n%divisor == 0
}

func reverseNumber(number int) int {
    reversedNumber := 0
    for ; number > 0; number /= 10 {
        reversedNumber = (reversedNumber * 10) + (number % 10)
    }
    return reversedNumber
}
