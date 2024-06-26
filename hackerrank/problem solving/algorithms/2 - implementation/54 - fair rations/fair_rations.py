# https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true
# From Python 3.8

def main():
    int(input())
    n_loaves_of_each_person = list(map(int, input().split()))
    if (min_loaves := find_min_loaves_to_satisfy_rules(n_loaves_of_each_person)) == - 1:
        print("NO")
    else:
        print(min_loaves)


def find_min_loaves_to_satisfy_rules(n_loaves_of_each_person):
    min_loaves_to_satisfy_rules = 0
    loaves = n_loaves_of_each_person[0]

    for x in n_loaves_of_each_person[1:]:
        if is_odd(loaves):
            loaves = x + 1
            min_loaves_to_satisfy_rules += 2
        else:
            loaves = x

    return -1 if is_odd(loaves) else min_loaves_to_satisfy_rules


def is_odd(n):
    return n % 2 == 1


if __name__ == '__main__':
    main()
