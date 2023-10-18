# https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

require 'date'

def main
    returned_real_date, due_date = read_stdin_dates
    book_return_date = BookReturnDate.new(returned_real_date, due_date)
    puts book_return_date.fine
end

    def read_stdin_dates
        date1, date2 = gets, gets
        returned_real_date = Date.strptime(date1, "%d %m %Y")
        due_date = Date.strptime(date2, "%d %m %Y")
        [returned_real_date, due_date]
    end

    class BookReturnDate
        def initialize(returned_real_date, due_date)
            @returned_real_date = returned_real_date
            @due_date = due_date
            @fineAmount = 0
            calculate_fine
        end

        private def calculate_fine
            if @returned_real_date <= @due_date
                @fineAmount = 0
            elsif @returned_real_date.year == @due_date.year
                if @returned_real_date.mon == @due_date.mon
                    @fineAmount = (@returned_real_date.mday - @due_date.mday) * HackosFine::HackosDaysFine
                else
                    @fineAmount = (@returned_real_date.mon - @due_date.mon) * HackosFine::HackosMonthsFine
                end
            else
                @fineAmount = HackosFine::HackosYearsFine
            end
            @fineAmount
        end

        def fine
            @fineAmount
        end    
    end

        module HackosFine
            HackosDaysFine = 15
            HackosMonthsFine = 500
            HackosYearsFine = 10000
        end

main
