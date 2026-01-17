// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

package main

import "fmt"

func main() {
    var startDay, endDay, divisor int
    _, _ = fmt.Scan(&startDay, &endDay, &divisor)
    fmt.Println(beautifulDays(startDay, endDay, divisor))
}

// n: range (endDay - startDay + 1)
// d: number of digits of the largest day
// T: O(n * d)
// S: O(1) extra space
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
    return (day-reverseNumber(day))%divisor == 0
}

func reverseNumber(number int) int {
    reversedNumber := 0
    for ; number > 0; number /= 10 {
        reversedNumber = (reversedNumber * 10) + (number % 10)
    }
    return reversedNumber
}
