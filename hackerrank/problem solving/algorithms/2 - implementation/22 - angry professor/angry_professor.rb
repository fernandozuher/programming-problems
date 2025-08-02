# https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

def main
  n = gets.to_i

  n.times.map do
    _, cancellation_threshold = read_numbers
    students_arrival_times = read_numbers
    angry_professor(students_arrival_times, cancellation_threshold)
  end.each { |x| puts x }
end

def read_numbers
  gets.split.map(&:to_i)
end

def angry_professor(arrival_times, cancellation_threshold)
  on_time = arrival_times.count { |t| t <= 0 }
  on_time < cancellation_threshold ? "YES" : "NO"
end

main if __FILE__ == $PROGRAM_NAME
