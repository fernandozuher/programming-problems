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

func calculateFine(returnDate, dueDate time.Time) int {
    if returnedOnTime(returnDate, dueDate) {
        return 0
    }
    if returnDate.Year() > dueDate.Year() {
        return HackosYearsFine
    }
    if returnDate.Month() > dueDate.Month() {
        return (int(returnDate.Month()) - int(dueDate.Month())) * HackosMonthsFine
    }
    return (returnDate.Day() - dueDate.Day()) * HackosDaysFine
}

func returnedOnTime(returnDate, dueDate time.Time) bool {
    return (returnDate.Year() < dueDate.Year()) ||
        ((returnDate.Year() == dueDate.Year()) && (int(returnDate.Month()) < int(dueDate.Month()))) ||
        ((returnDate.Year() == dueDate.Year()) && (int(returnDate.Month()) == int(dueDate.Month())) && (returnDate.Day() <= dueDate.Day()))
}
