# https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

def main
  positions_and_velocities = read_numbers
  puts kangaroo(positions_and_velocities) ? "YES" : "NO"
end

def read_numbers
  gets.split.map(&:to_i)
end

def kangaroo(positions_and_velocities)
  x1, v1, x2, v2 = positions_and_velocities

  return x1 == x2 if v1 == v2

  distance_diff = x2 - x1
  velocity_diff = v1 - v2
  distance_diff * velocity_diff >= 0 && distance_diff % velocity_diff == 0
end

main
