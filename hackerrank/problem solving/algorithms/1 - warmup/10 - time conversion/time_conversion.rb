# https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

def main
    time = gets
    puts time_conversion(time)
end

    def time_conversion(time)
        converted_time = time[0, 8]
        hour = time[0, 2]
        dayPeriod = time[8, 1]

        if hour == "12"
            if dayPeriod == "A"
                midnight = "00"
                converted_time[0, 2] = midnight
            end
        elsif dayPeriod == "P"
            new_hour = hour.to_i
            new_hour += 12
            converted_time[0, 2] = new_hour.to_s
        end

        converted_time
    end

main
