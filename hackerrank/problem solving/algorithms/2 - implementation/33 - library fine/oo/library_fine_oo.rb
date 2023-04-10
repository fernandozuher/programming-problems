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

    obj = LibraryFine.new returnDate, dueDate
    fine = obj.getFine
    puts fine
end

    def readADate
        date = Date.strptime(gets, "%d %m %Y")
    end

    class LibraryFine
        @returnDate
        @dueDate
        @fine

        def initialize returnDate, dueDate
            @returnDate = returnDate
            @dueDate = dueDate
            @fine = 0

            _calculateFine
        end

            private def _calculateFine
                if _wereBooksReturnedInTime
                    @fine = 0
                elsif _isReturnDateLateInMoreThanOrEqualToOneYear
                    @fine = HackosFine::HackosYearsFine
                elsif _isReturnDateLateInMoreThanOrEqualToOneMonth
                    @fine = (@returnDate.mon - @dueDate.mon) * HackosFine::HackosMonthsFine
                else
                    @fine = (@returnDate.mday - @dueDate.mday) * HackosFine::HackosDaysFine
                end
            end

                private def _wereBooksReturnedInTime
                    if (@returnDate.year < @dueDate.year) ||
                        ((@returnDate.year == @dueDate.year) && (@returnDate.mon < @dueDate.mon)) ||
                        ((@returnDate.year == @dueDate.year) && (@returnDate.mon == @dueDate.mon) && (@returnDate.mday <= @dueDate.mday))
                        return true
                    end
                    return false
                end

                private def _isReturnDateLateInMoreThanOrEqualToOneYear
                    @returnDate.year > @dueDate.year
                end

                private def _isReturnDateLateInMoreThanOrEqualToOneMonth
                    @returnDate.mon > @dueDate.mon
                end

        def getFine
            @fine
        end
    end

main