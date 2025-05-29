# https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

def main
  n = gets.to_i
  grades = read_numbers(n)
  rounded_grades = grade_students(grades)
  puts rounded_grades
end

def read_numbers(n)
  Array.new(n) { gets.to_i }
end

def grade_students(grades)
  min_grade = 38
  grades.map do |grade|
    if grade < min_grade
      grade
    else
      next_multiple5 = (grade / 5 + 1) * 5
      (next_multiple5 - grade < 3) ? next_multiple5 : grade
    end
  end
end

main
