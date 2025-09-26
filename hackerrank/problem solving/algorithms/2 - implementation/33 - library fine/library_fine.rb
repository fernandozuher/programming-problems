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

def calculate_fine(return_date, due_date)
  return 0 if returned_on_time(return_date, due_date)
  return HackosFine::YEARS_FINE if return_date.year > due_date.year
  return (return_date.mon - due_date.mon) * HackosFine::MONTHS_FINE if return_date.year == due_date.year && return_date.mon > due_date.mon
  (return_date.mday - due_date.mday) * HackosFine::DAYS_FINE
end

def returned_on_time(return_date, due_date)
  (return_date.year < due_date.year) ||
    ((return_date.year == due_date.year) && (return_date.mon < due_date.mon)) ||
    ((return_date.year == due_date.year) && (return_date.mon == due_date.mon) && (return_date.mday <= due_date.mday))
end

main if __FILE__ == $PROGRAM_NAME
