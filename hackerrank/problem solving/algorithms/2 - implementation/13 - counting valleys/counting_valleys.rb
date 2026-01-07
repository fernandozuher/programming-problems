# https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

def main
  gets
  steps = gets
  puts counting_valleys(steps)
end

# n: length of steps
# T: O(n)
# S: O(1) extra space
def counting_valleys(steps)
  valleys = 0
  current_altitude = 0

  steps.each_char do |step|
    was_below_sea_level = current_altitude < 0
    current_altitude += step == 'D' ? -1 : 1
    is_in_sea_level_from_valley = was_below_sea_level && current_altitude == 0
    valleys += 1 if is_in_sea_level_from_valley
  end

  valleys
end

main if __FILE__ == $0
