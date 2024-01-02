# https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

def main
    n = gets.to_i
    chocolate_squares = read_int_array
    day_month = read_int_array

    obj = TheBirthdayBar.new(chocolate_squares, day_month)
    puts obj.ways_bar_can_be_divided
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class TheBirthdayBar

        def initialize(chocolate_squares, day_month)
            @chocolate_squares = chocolate_squares
            @day = day_month[0]
            @month = day_month[1]
            @n_divisions = 0

            birthday
        end

            private def birthday
                for i in 0..(@chocolate_squares.size - @month)
                    sum = 0

                    for j in i..(i + @month - 1)
                        sum += @chocolate_squares[j]
                    end

                    if sum == @day
                        @n_divisions += 1
                    end
                end
            end

            def ways_bar_can_be_divided
                @n_divisions
            end
    end

main
