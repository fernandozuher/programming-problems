#!/bin/ruby

#
# Complete the 'factorial' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER n as parameter.
#
def factorial(n)
    return n == 1 ? 1 : n * factorial(n-1)
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.strip.to_i

result = factorial n

fptr.write result
fptr.write "\n"

fptr.close()
