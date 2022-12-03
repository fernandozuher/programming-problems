#!/bin/ruby

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion time
    convertedTime = time[0, 8]
    hourString = time[0, 2]
    periodOfDay = time[8, 1]

    if hourString == "12"
        if periodOfDay == "A"
            convertedTime[0, 2] = "00"
        end
    elsif periodOfDay == "P"
        hour = hourString.to_i
        hour += 12
        convertedTime[0, 2] = hour.to_s
    end
    convertedTime
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

s = gets.chomp

result = timeConversion s

fptr.write result
fptr.write "\n"

fptr.close()
