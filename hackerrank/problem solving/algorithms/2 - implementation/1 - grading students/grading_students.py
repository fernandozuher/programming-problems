# https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true

def main():
    
    n = int(input())
    array = read_int_array(n)
    print(*grading_students(array), sep='\n')


def read_int_array(n):

    return [int(input()) for _ in range(n)]


def grading_students(grades):

    n = len(grades)
    new_grades = [None] * n
    MIN_GRADE = 38

    for i in range(n):

        if grades[i] < MIN_GRADE or is_zero_remainder(grades[i]):
            new_grades[i] = grades[i]
        else:
            quocient = int(grades[i] / 5)
            next_multiple5 = (quocient + 1) * 5
            difference = next_multiple5 - grades[i]

            result = next_multiple5 if difference < 3 else grades[i]
            new_grades[i] = result

    return new_grades


def is_zero_remainder(grade):

    return grade % 5 == 0


if __name__ == '__main__':
    main()
