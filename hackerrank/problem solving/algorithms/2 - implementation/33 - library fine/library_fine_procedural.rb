# Source: https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

require 'date'

module HackosFine
    HackosDaysFine = 15
    HackosMonthsFine = 500
    HackosYearsFine = 10000
end

def main
    returnDate = readADate()
    dueDate = readADate()

    fine = calculateFine(returnDate, dueDate)
    puts fine
end

    def readADate
        date = Date.strptime(gets, "%d %m %Y")
    end

    def calculateFine returnDate, dueDate
        fine = 0

        if wereBooksReturnedInTime returnDate, dueDate
            fine = 0
        elsif isReturnDateLateInMoreThanOrEqualToOneYear returnDate.year, dueDate.year
            fine = HackosFine::HackosYearsFine
        elsif isReturnDateLateInMoreThanOrEqualToOneMonth returnDate.mon, dueDate.mon
            fine = (returnDate.mon - dueDate.mon) * HackosFine::HackosMonthsFine
        else
            fine = (returnDate.mday - dueDate.mday) * HackosFine::HackosDaysFine
        end

        fine
    end

        def wereBooksReturnedInTime returnDate, dueDate
            if (returnDate.year < dueDate.year) ||
                ((returnDate.year == dueDate.year) && (returnDate.mon < dueDate.mon)) ||
                ((returnDate.year == dueDate.year) && (returnDate.mon == dueDate.mon) && (returnDate.mday <= dueDate.mday))
                return true
            end
            return false
        end

        def isReturnDateLateInMoreThanOrEqualToOneYear returnDateYear, dueDateYear
            returnDateYear > dueDateYear
        end

        def isReturnDateLateInMoreThanOrEqualToOneMonth returnDateMonth, dueDateMonth
            returnDateMonth > dueDateMonth
        end

main