# https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

TRANSITION_YEAR = 1918

def main
  year = gets.to_i
  puts calculate_date_of_256th_day(year)
end

def calculate_date_of_256th_day(year)
  if year == TRANSITION_YEAR
    day = '26'
  else
    day = leap_year?(year) ? '12' : '13'
  end
  day + ".09." + year.to_s
end

def leap_year?(year)
  return leap_julian_year?(year) if year < TRANSITION_YEAR
  return leap_gregorian_year?(year) if year > TRANSITION_YEAR
  false
end

def leap_julian_year?(year)
  year % 4 == 0
end

def leap_gregorian_year?(year)
  year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)
end

main
