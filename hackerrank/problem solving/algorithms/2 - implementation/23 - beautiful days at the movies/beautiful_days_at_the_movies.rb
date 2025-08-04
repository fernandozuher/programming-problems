# https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

def main
  start_day, end_day, divisor = read_numbers
  puts beautiful_days(start_day, end_day, divisor)
end

def read_numbers
  gets.split.map(&:to_i)
end

def beautiful_days(start_day, end_day, divisor)
  (start_day..end_day).count { |day| beautiful_day?(day, divisor) }
end

def beautiful_day?(day, divisor)
  (day - reverse_number(day)).abs % divisor == 0
end

def reverse_number(number)
  number.to_s.reverse.to_i
end

main if __FILE__ == $PROGRAM_NAME
