#!/bin/ruby

#
# Complete the 'gradingStudents' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY grades as parameter.
#

def isZeroRemainder grade
    grade % 5 == 0
end

def gradingStudents grades
    n = grades.length
    newGrades = Array.new n
    minGrade = 38

    for i in 0..n-1
        if grades[i] < minGrade or isZeroRemainder grades[i]
            newGrades[i] = grades[i]
        else
            quocient = (grades[i] / 5).to_i
            nextMultiple5 = (quocient + 1) * 5
            difference = nextMultiple5 - grades[i]

            result = difference < 3 ? nextMultiple5 : grades[i]
            newGrades[i] = result
        end
    end
    newGrades
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

grades_count = gets.strip.to_i

grades = Array.new(grades_count)

grades_count.times do |i|
    grades_item = gets.strip.to_i
    grades[i] = grades_item
end

result = gradingStudents grades

fptr.write result.join "\n"
fptr.write "\n"

fptr.close()
