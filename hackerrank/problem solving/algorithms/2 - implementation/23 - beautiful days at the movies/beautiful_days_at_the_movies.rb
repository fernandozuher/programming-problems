# https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

def main
    starting_day_number, ending_day_number, divisor = read_int_array
    obj = BeautifulDays.new(starting_day_number, ending_day_number, divisor)
    puts obj.n_beautiful_days
end

    def read_int_array
        gets.split.map(&:to_i)
    end

    class BeautifulDays
        attr_reader :n_beautiful_days

        def initialize(starting_day_number, ending_day_number, divisor)
            @starting_day_number = starting_day_number
            @ending_day_number = ending_day_number
            @divisor = divisor
            @n_beautiful_days = 0
            calculate_beautiful_days_quantity
        end

            def calculate_beautiful_days_quantity
                for number in @starting_day_number..@ending_day_number
                    reverse_number = generate_reverse_number(number)

                    if is_day_beautiful(number, reverse_number)
                        @n_beautiful_days += 1
                    end
                end
            end

                def generate_reverse_number(number)
                    reverse_number = 0

                    while number > 0
                        reverse_number = (reverse_number * 10) + (number % 10)
                        number = (number / 10).to_i
                    end

                    reverse_number
                end

                def is_day_beautiful(number, reverse_number)
                    (number - reverse_number).abs % @divisor == 0
                end
    end

main
