// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

package main

import (
    "fmt"
    "time"
)

const (
    HackosDaysFine   int = 15
    HackosMonthsFine     = 500
    HackosYearsFine      = 10000
)

func main() {
    returnDate := readDate()
    dueDate := readDate()
    fmt.Println(calculateFine(returnDate, dueDate))
}

func readDate() time.Time {
    var day, month, year int
    _, _ = fmt.Scan(&day, &month, &year)
    return time.Date(year, time.Month(month), day, 0, 0, 0, 0, time.UTC)
}

// T: O(1)
// S: O(1) extra space
func calculateFine(returnDate, dueDate time.Time) int {
    if isYearLate(returnDate, dueDate) {
        return HackosYearsFine
    }
    if isMonthLate(returnDate, dueDate) {
        return (int(returnDate.Month()) - int(dueDate.Month())) * HackosMonthsFine
    }
    if isDayLate(returnDate, dueDate) {
        return (returnDate.Day() - dueDate.Day()) * HackosDaysFine
    }
    return 0
}

func isYearLate(returnDate, dueDate time.Time) bool {
    return returnDate.Year() > dueDate.Year()
}

func isMonthLate(returnDate, dueDate time.Time) bool {
    return returnDate.Year() == dueDate.Year() && returnDate.Month() > dueDate.Month()
}

func isDayLate(returnDate, dueDate time.Time) bool {
    return returnDate.Year() == dueDate.Year() && returnDate.Month() == dueDate.Month() && returnDate.Day() > dueDate.Day()
}
