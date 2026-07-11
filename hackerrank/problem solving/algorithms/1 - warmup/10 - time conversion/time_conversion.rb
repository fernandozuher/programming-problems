# https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

def main
  time = gets
  puts to_24_hour_time(time)
end

# T: O(1)
# S: O(1) extra space
def to_24_hour_time(hour_12)
  hour_24 = hour_12[0, 8]
  hour = hour_12[0, 2]
  day_period = hour_12[8, 1]

  if (hour == '12' && day_period == 'A') || (hour != '12' && day_period == 'P')
    hour_24[0, 2] = gen_new_hour(day_period, hour)
  end

  hour_24
end

def gen_new_hour(day_period, hour)
  return '00' if day_period == 'A'
  new_hour = hour.to_i
  new_hour += 12
  new_hour.to_s
end

main if __FILE__ == $0
