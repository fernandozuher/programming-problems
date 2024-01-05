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
    fmt.Print(findDateOf256thDay(year))
}

    func findDateOf256thDay(year int) string {
        var date string = findDayMonthOf256thDay(year)
        date = addYearToDate(year, date)
        return date
    }

        func findDayMonthOf256thDay(year int) string {
            if year != TransitionYear {
                if isLeapYear(year) {
                    return "12.09."
                } else {
                    return "13.09."
                }
            } else {
                return "26.09."
            }
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

        func addYearToDate(year int, date string) string {
            return date + strconv.Itoa(year)
        }
