# https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

def main
  n = gets.to_i
  array = read_int_array(n)
  puts grading_students(array)
end

  def read_int_array(n)
    Array.new(n) { gets.to_i }
  end

  def grading_students(grades)
    new_grades = Array.new(grades.length)
    min_grade = 38

    grades.each_with_index { |grade, i|
      if grade < min_grade or is_zero_remainder(grade)
        new_grades[i] = grade
      else
        quotient = (grade / 5).to_i
        next_multiple5 = (quotient + 1) * 5
        difference = next_multiple5 - grade
        new_grades[i] = difference < 3 ? next_multiple5 : grade
      end
    }

    new_grades
  end

    def is_zero_remainder(grade)
      grade % 5 == 0
    end

main
