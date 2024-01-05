# https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

def main
    year = gets.to_i
    obj = DayOfTheProgrammer.new(year)
    puts obj.date
end

    class DayOfTheProgrammer
        attr_reader :date

        def initialize year
            @year = year
            @date = ''
            @TRANSITION_YEAR = 1918
            find_date_of_256th_day
        end

            private def find_date_of_256th_day
                find_day_month_of_256th_day
                @date += @year.to_s
            end

                private def find_day_month_of_256th_day
                    if @year != @TRANSITION_YEAR
                        @date = is_leap_year ? "12.09." : "13.09."
                    else
                        @date = "26.09."
                    end
                end

                    private def is_leap_year
                        @year > @TRANSITION_YEAR ? is_leap_gregorian_year : is_leap_julian_year
                    end

                        private def is_leap_gregorian_year
                            @year % 400 == 0 || (@year % 4 == 0 && @year % 100 != 0)
                        end

                        private def is_leap_julian_year
                            @year % 4 == 0
                        end
    end

main
