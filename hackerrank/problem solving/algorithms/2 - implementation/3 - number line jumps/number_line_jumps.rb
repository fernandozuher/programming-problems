# Source: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

#!/bin/ruby

#
# Complete the 'kangaroo' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. INTEGER x1
#  2. INTEGER v1
#  3. INTEGER x2
#  4. INTEGER v2
#

def kangaroo x1, v1, x2, v2
    if v2 >= v1
        return "NO"
    end
    while x1 < x2
        x1 += v1
        x2 += v2
    end
    x1 == x2 ? "YES" : "NO";
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

numbers = gets.split.map(&:to_i)
x1 = numbers[0]
v1 = numbers[1]
x2 = numbers[2]
v2 = numbers[3]

result = kangaroo x1, v1, x2, v2
fptr.write result
fptr.write "\n"

fptr.close()
