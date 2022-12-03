#!/bin/python3

import os

#
# Complete the 'gradingStudents' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY grades as parameter.
#

def isZeroRemainder(grade):
    return grade % 5 == 0

def gradingStudents(grades):
    N = len(grades)
    newGrades = [None] * N
    MIN_GRADE = 38

    for i in range(N):
        if grades[i] < MIN_GRADE or isZeroRemainder(grades[i]):
            newGrades[i] = grades[i]
        else:
            quocient = int(grades[i] / 5)
            nextMultiple5 = (quocient + 1) * 5
            difference = nextMultiple5 - grades[i]

            result = nextMultiple5 if difference < 3 else grades[i]
            newGrades[i] = result

    return newGrades

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    grades_count = int(input().strip())

    grades = []

    for _ in range(grades_count):
        grades_item = int(input().strip())
        grades.append(grades_item)

    result = gradingStudents(grades)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
