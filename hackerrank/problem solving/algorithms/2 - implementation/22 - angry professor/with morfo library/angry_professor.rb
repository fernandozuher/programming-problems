# https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

require 'morfo'

def main
  n = Morfo.read(&:to_i)
  n.times do
    Morfo.skip_input
    threshold = Morfo.read(&:to_i)
    arrival_times = Morfo.readln(&:to_i)
    puts angry_professor?(arrival_times, threshold) ? "YES" : "NO"
  end
end

# k: length of arrival_times
# T: O(k)
# S: O(1) extra space
def angry_professor?(arrival_times, threshold)
  on_time = arrival_times.count { _1 <= 0 }
  on_time < threshold
end

main if __FILE__ == $0
