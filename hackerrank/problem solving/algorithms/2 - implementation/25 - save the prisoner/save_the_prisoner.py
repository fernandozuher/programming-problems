# https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

def main():

    n = int(input())
    prisoners_chair_number_to_warn = [None] * n

    for i in range(n):
        prisoners, sweets, chair_number_to_begin = read_int_array()
        prisoners_chair_number_to_warn[i] = save_the_prisoner(prisoners, sweets, chair_number_to_begin)

    print(*prisoners_chair_number_to_warn, sep='\n')


def read_int_array():

    return list(map(int, input().split()))


def save_the_prisoner(prisoners, sweets, chair_number_to_begin):

    prisoner_chair_number_to_warn = chair_number_to_begin + (sweets - 1)
    x = prisoner_chair_number_to_warn

    if x > prisoners:
        x %= prisoners
        if x == 0:
            x = prisoners

    return x


if __name__ == '__main__':
    main()
