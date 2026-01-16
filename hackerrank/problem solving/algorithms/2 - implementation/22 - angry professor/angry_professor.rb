# https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

def main
  n = gets.to_i
  n.times do
    _, threshold = read_numbers
    arrival_times = read_numbers
    puts angry_professor(arrival_times, threshold) ? "YES" : "NO"
  end
end

def read_numbers
  gets&.split&.map!(&:to_i)
end

# k: length of array arrival_times
# T: O(k)
# S: O(1) extra space
def angry_professor(arrival_times, threshold)
  on_time = arrival_times.count { |t| t <= 0 }
  on_time < threshold
end

main if __FILE__ == $0
