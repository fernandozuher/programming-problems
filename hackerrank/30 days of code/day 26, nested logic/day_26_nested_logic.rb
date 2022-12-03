require 'date'

module HackosFine
    HackosDaysFine = 15
    HackosMonthsFine = 500
    HackosYearsFine = 10000
end

class BookReturnDate
    def initialize(returned_real_date, due_date)
        @returned_real_date = returned_real_date
        @due_date = due_date
        @fine = 0
        calculate_fine
    end

    def get_fine
        @fine
    end

private

    def calculate_fine
        if @returned_real_date <= @due_date
            @fine = 0
        elsif @returned_real_date.year == @due_date.year
            if @returned_real_date.mon == @due_date.mon
                @fine = (@returned_real_date.mday - @due_date.mday) * HackosFine::HackosDaysFine
            else
                @fine = (@returned_real_date.mon - @due_date.mon) * HackosFine::HackosMonthsFine
            end
        else
            @fine = HackosFine::HackosYearsFine
        end
        @fine
    end    
end

def read_stdin_dates
    date1, date2 = gets, gets
    returned_real_date = Date.strptime(date1, "%d %m %Y")
    due_date = Date.strptime(date2, "%d %m %Y")
    [returned_real_date, due_date]
end

returnedRealDate, dueDate = read_stdin_dates
bookReturnDateObj = BookReturnDate.new(returnedRealDate, dueDate)
puts bookReturnDateObj.get_fine
