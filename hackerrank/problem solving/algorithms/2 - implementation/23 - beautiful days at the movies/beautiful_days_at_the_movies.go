// Source: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

package main

import (
    "fmt"
    "math"
)

func main() {
    var startingDayNumber int = readOneInt()
    var endingDayNumber int = readOneInt()
    var divisor int = readOneInt()

    var nBeautifulDays int = beautifulDays(startingDayNumber, endingDayNumber, divisor)

    fmt.Println(nBeautifulDays)
}

    func readOneInt() int {
        var number int
        fmt.Scan(&number)
        return number
    }

    func beautifulDays(startingDayNumber int, endingDayNumber int, divisor int) int {
        var nBeautifulDays int = 0

        for number := startingDayNumber; number <= endingDayNumber; number++ {
            var reverseNumber int = generateReverseNumber(number)

            if isDayBeautiful(number, reverseNumber, divisor) {
                nBeautifulDays++
            }
        }

        return nBeautifulDays
    }

        func generateReverseNumber(number int) int {
            var reverseNumber int = 0
            for ; number > 0; number /= 10 {
                reverseNumber = (reverseNumber * 10) + (number % 10)
            }
            return reverseNumber
        }

        func isDayBeautiful(number int, reverseNumber int, divisor int) bool {
            var beautifulDay bool = int(math.Abs(float64(number) - float64(reverseNumber))) % divisor == 0
            return beautifulDay
        }
