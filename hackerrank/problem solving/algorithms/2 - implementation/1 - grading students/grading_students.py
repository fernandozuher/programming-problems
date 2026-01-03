# https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

def main():
    n = int(input())
    grades = read_numbers(n)
    grading_students(grades)
    print(*grades, sep='\n')


def read_numbers(n):
    return [int(input()) for _ in range(n)]


# n: length of array grades
# T: O(n)
# S: O(1) extra space
def grading_students(grades):
    MIN_GRADE = 38

    for i, grade in enumerate(grades):
        if grade >= MIN_GRADE:
            next_multiple_5 = (grade // 5 + 1) * 5
            if next_multiple_5 - grade < 3:
                grades[i] = next_multiple_5


if __name__ == '__main__':
    main()