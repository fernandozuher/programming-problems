# https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

require 'date'

module HackosFine
    HackosDaysFine = 15
    HackosMonthsFine = 500
    HackosYearsFine = 10000
end

def main
    return_date = read_a_date
    due_date = read_a_date
    obj = LibraryFine.new(return_date, due_date)
    puts obj.fine
end

    def read_a_date
        Date.strptime(gets, "%d %m %Y")
    end

    class LibraryFine
        attr_reader :fine

        def initialize(return_date, due_date)
            @return_date = return_date
            @due_date = due_date
            @fine = 0
            calculate_fine
        end

            private def calculate_fine
                if were_books_returned_in_time
                    @fine = 0
                elsif is_return_date_late_in_more_than_or_equal_to_one_year
                    @fine = HackosFine::HackosYearsFine
                elsif is_return_date_late_in_more_than_or_equal_to_one_month
                    @fine = (@return_date.mon - @due_date.mon) * HackosFine::HackosMonthsFine
                else
                    @fine = (@return_date.mday - @due_date.mday) * HackosFine::HackosDaysFine
                end
            end

                private def were_books_returned_in_time
                    if (@return_date.year < @due_date.year) ||
                        ((@return_date.year == @due_date.year) && (@return_date.mon < @due_date.mon)) ||
                        ((@return_date.year == @due_date.year) && (@return_date.mon == @due_date.mon) && (@return_date.mday <= @due_date.mday))
                        return true
                    end
                    return false
                end

                private def is_return_date_late_in_more_than_or_equal_to_one_year
                    @return_date.year > @due_date.year
                end

                private def is_return_date_late_in_more_than_or_equal_to_one_month
                    @return_date.mon > @due_date.mon
                end
    end

main
