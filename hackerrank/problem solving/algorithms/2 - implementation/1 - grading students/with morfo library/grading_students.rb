# https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

require 'morfo'

def main
  n = Morfo.read(&:to_i)
  grades = Morfo.read(n, &:to_i)
  puts grading_students(grades)
end

# n: length of grades
# T: O(n)
# S: O(1) extra space
def grading_students(grades)
  min_grade = 38
  grades.each_with_index do |grade, i|
    next if grade < min_grade
    next_multiple_5 = (grade / 5 + 1) * 5
    grades[i] = next_multiple_5 if (next_multiple_5 - grade < 3)
  end
end

main if __FILE__ == $0
