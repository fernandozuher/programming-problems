# https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

require 'morfo'

def main
  start_day, end_day, divisor = Morfo.read(3, &:to_i)
  puts beautiful_days(start_day, end_day, divisor)
end

# n: range (end_day - start_day + 1)
# d: number of digits of the largest day
# T: O(n * d)
# S: O(d) extra space
def beautiful_days(start_day, end_day, divisor) = (start_day..end_day).count { beautiful_day?(_1, divisor) }

def beautiful_day?(day, divisor) = ((day - reverse_number(day)) % divisor).zero?

def reverse_number(number) = number.to_s.reverse.to_i

main if __FILE__ == $0
