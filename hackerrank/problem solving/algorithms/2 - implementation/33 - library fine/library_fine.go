// Source: https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

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
    returnDate := ReadADate()
    dueDate := ReadADate()

    var fine int = CalculateFine(returnDate, dueDate)
    fmt.Println(fine)
}

    func ReadADate() time.Time {
        var day, month, year int
        fmt.Scan(&day)
        fmt.Scan(&month)
        fmt.Scan(&year)

        date := time.Date(year, time.Month(month), day, 0, 0, 0, 0, time.UTC)
        return date
    }

    func CalculateFine(returnDate time.Time, dueDate time.Time) int {
        var fine int

        if WereBooksReturnedInTime(returnDate, dueDate) {
            fine = 0
        } else if IsReturnDateLateInMoreThanOrEqualToOneYear(returnDate.Year(), dueDate.Year()) {
            fine = HackosYearsFine
        } else if IsReturnDateLateInMoreThanOrEqualToOneMonth(int(returnDate.Month()), int(dueDate.Month())) {
            fine = (int(returnDate.Month()) - int(dueDate.Month())) * HackosMonthsFine
        } else {
            fine = (returnDate.Day() - dueDate.Day()) * HackosDaysFine
        }

        return fine
    }

        func WereBooksReturnedInTime(returnDate time.Time, dueDate time.Time) bool {
            if (returnDate.Year() < dueDate.Year()) ||
                ((returnDate.Year() == dueDate.Year()) && (int(returnDate.Month()) < int(dueDate.Month()))) ||
                ((returnDate.Year() == dueDate.Year()) && (int(returnDate.Month()) == int(dueDate.Month())) && (returnDate.Day() <= dueDate.Day())) {
                return true
            }
            return false
        }

        func IsReturnDateLateInMoreThanOrEqualToOneYear(returnDateYear int, dueDateYear int) bool {
            return returnDateYear > dueDateYear
        }

        func IsReturnDateLateInMoreThanOrEqualToOneMonth(returnDateMonth int, dueDateMonth int) bool {
            return returnDateMonth > dueDateMonth
        }
