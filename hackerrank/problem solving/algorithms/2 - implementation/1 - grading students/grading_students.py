# https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

def main():
    n = int(input())
    grades = read_numbers(n)
    rounded_grades = grade_students(grades)
    print(*rounded_grades, sep='\n')


def read_numbers(n):
    return [int(input()) for _ in range(n)]


def grade_students(grades):
    MIN_GRADE = 38
    rounded_grades = [0] * len(grades)

    for i, grade in enumerate(grades):
        if grade < MIN_GRADE:
            rounded_grades[i] = grade
        else:
            next_multiple_5 = (grade // 5 + 1) * 5
            rounded_grades[i] = next_multiple_5 if (next_multiple_5 - grade < 3) else grade

    return rounded_grades


if __name__ == '__main__':
    main()
