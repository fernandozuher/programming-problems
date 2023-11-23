# https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

def main
    n = gets.to_i
    array = read_int_array(n)
    puts grading_students(array)
end

    def read_int_array(n)
        Array.new(n){gets.to_i}
    end

    def grading_students(grades)
        new_grades = Array.new(grades.length)
        min_grade = 38

        grades.size.times do |i|
            if grades[i] < min_grade or is_zero_remainder(grades[i])
                new_grades[i] = grades[i]
            else
                quocient = (grades[i] / 5).to_i
                next_multiple5 = (quocient + 1) * 5
                difference = next_multiple5 - grades[i]

                result = difference < 3 ? next_multiple5 : grades[i]
                new_grades[i] = result
            end
        end

        new_grades
    end

        def is_zero_remainder(grade)
            grade % 5 == 0
        end

main
