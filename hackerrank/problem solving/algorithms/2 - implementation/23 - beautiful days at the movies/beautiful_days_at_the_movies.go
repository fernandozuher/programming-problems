// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

package main

import (
    "fmt"
)

func main() {
    var startingDayNumber, endingDayNumber, divisor int
    fmt.Scan(&startingDayNumber, &endingDayNumber, &divisor)
    fmt.Println(beautifulDays(startingDayNumber, endingDayNumber, divisor))
}

func beautifulDays(startingDayNumber, endingDayNumber, divisor int) int {
    nBeautifulDays := 0
    for number := startingDayNumber; number <= endingDayNumber; number++ {
        reverseNumber := generateReverseNumber(number)
        if isDayBeautiful(number, reverseNumber, divisor) {
            nBeautifulDays++
        }
    }
    return nBeautifulDays
}

func generateReverseNumber(number int) int {
    reverseNumber := 0
    for ; number > 0; number /= 10 {
        reverseNumber = (reverseNumber * 10) + (number % 10)
    }
    return reverseNumber
}

func isDayBeautiful(number, reverseNumber, divisor int) bool {
    return absInt(number-reverseNumber)%divisor == 0
}

func absInt(number int) int {
    if number < 0 {
        return -number
    }
    return number
}
