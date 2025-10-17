# https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

def main
  _, n = read_numbers
  widths = read_numbers
  n.times { puts max_affordable_width_vehicle_in_range(widths, read_numbers) }
end

def read_numbers
  gets.split.map(&:to_i)
end

def max_affordable_width_vehicle_in_range(widths, point)
  start, finish = point
  widths[start..finish].min
end

main if __FILE__ == $PROGRAM_NAME
