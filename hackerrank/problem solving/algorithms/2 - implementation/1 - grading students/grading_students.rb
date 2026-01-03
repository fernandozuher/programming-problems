# https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

def main
  n = gets.to_i
  grades = read_numbers(n)
  puts grading_students!(grades)
end

def read_numbers(n)
  Array.new(n) { gets.to_i }
end

# n: length of array grades
# T: O(n)
# S: O(1) extra space
def grading_students!(grades)
  min_grade = 38
  grades.map! do |grade|
    if grade < min_grade
      grade
    else
      next_multiple_5 = (grade / 5 + 1) * 5
      (next_multiple_5 - grade < 3) ? next_multiple_5 : grade
    end
  end
end

main if __FILE__ == $PROGRAM_NAME