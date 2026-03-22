# https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

require 'date'

module HackosFine
  DAYS_FINE = 15
  MONTHS_FINE = 500
  YEARS_FINE = 10000
end

def main
  return_date = read_date
  due_date = read_date
  puts calculate_fine(return_date, due_date)
end

def read_date
  Date.strptime(gets, "%d %m %Y")
end

# T: O(1)
# S: O(1) extra space
def calculate_fine(return_date, due_date)
  return HackosFine::YEARS_FINE if late_year?(return_date, due_date)
  return (return_date.mon - due_date.mon) * HackosFine::MONTHS_FINE if late_month?(return_date, due_date)
  return (return_date.mday - due_date.mday) * HackosFine::DAYS_FINE if late_day?(return_date, due_date)
  0
end

def late_year?(return_date, due_date)
  return_date.year > due_date.year
end

def late_month?(return_date, due_date)
  return_date.year == due_date.year && return_date.month > due_date.month
end

def late_day?(return_date, due_date)
  return_date.year == due_date.year && return_date.month == due_date.month && return_date.day > due_date.day
end

main if __FILE__ == $0
