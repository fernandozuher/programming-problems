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
    var returnDate time.Time = readADate()
    var dueDate time.Time = readADate()
    fmt.Println(calculateFine(returnDate, dueDate))
}

    func readADate() time.Time {
        var day, month, year int
        fmt.Scan(&day, &month, &year)
        return time.Date(year, time.Month(month), day, 0, 0, 0, 0, time.UTC)
    }

    func calculateFine(returnDate time.Time, dueDate time.Time) int {
        var fine int

        if wereBooksReturnedInTime(returnDate, dueDate) {
            fine = 0
        } else if isReturnDateLateInMoreThanOrEqualToOneYear(returnDate.Year(), dueDate.Year()) {
            fine = HackosYearsFine
        } else if isReturnDateLateInMoreThanOrEqualToOneMonth(int(returnDate.Month()), int(dueDate.Month())) {
            fine = (int(returnDate.Month()) - int(dueDate.Month())) * HackosMonthsFine
        } else {
            fine = (returnDate.Day() - dueDate.Day()) * HackosDaysFine
        }

        return fine
    }

        func wereBooksReturnedInTime(returnDate time.Time, dueDate time.Time) bool {
            if (returnDate.Year() < dueDate.Year()) ||
                ((returnDate.Year() == dueDate.Year()) && (int(returnDate.Month()) < int(dueDate.Month()))) ||
                ((returnDate.Year() == dueDate.Year()) && (int(returnDate.Month()) == int(dueDate.Month())) && (returnDate.Day() <= dueDate.Day())) {
                return true
            }
            return false
        }

        func isReturnDateLateInMoreThanOrEqualToOneYear(returnDateYear int, dueDateYear int) bool {
            return returnDateYear > dueDateYear
        }

        func isReturnDateLateInMoreThanOrEqualToOneMonth(returnDateMonth int, dueDateMonth int) bool {
            return returnDateMonth > dueDateMonth
        }
