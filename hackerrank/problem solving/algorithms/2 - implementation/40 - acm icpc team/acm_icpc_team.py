# https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

from itertools import combinations


def main():
    n, _ = read_numbers()
    binaries = read_binaries(n)
    print(*acm_team(binaries), sep='\n')


def read_numbers():
    return list(map(int, input().split()))


def read_binaries(n):
    return [int(input().strip(), 2) for _ in range(n)]


def acm_team(binaries):
    max_subjects = 0
    teams_with_max = 0

    for a, b in combinations(binaries, 2):
        known_subjects = (a | b).bit_count()

        if known_subjects > max_subjects:
            max_subjects = known_subjects
            teams_with_max = 1
        elif known_subjects == max_subjects:
            teams_with_max += 1

    return max_subjects, teams_with_max


if __name__ == '__main__':
    main()
