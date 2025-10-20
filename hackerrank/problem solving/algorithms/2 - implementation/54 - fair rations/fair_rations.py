# https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

def main():
    input()
    people_loaf_counts = read_numbers()
    if (min_loaves := min_loaves_to_satisfy_rules(people_loaf_counts)) == - 1:
        print("NO")
    else:
        print(min_loaves)


def read_numbers():
    return list(map(int, input().split()))


def min_loaves_to_satisfy_rules(people_loaf_counts):
    loaves_given = 0
    counts = people_loaf_counts[0]

    for x in people_loaf_counts[1:]:
        if is_odd(counts):
            loaves_given += 2
            counts = x + 1
        else:
            counts = x

    return -1 if is_odd(counts) else loaves_given


def is_odd(n):
    return n % 2 == 1


if __name__ == '__main__':
    main()
