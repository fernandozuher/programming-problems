# https://www.hackerrank.com/challenges/acm-icpc-team/problem?isFullScreen=true

from itertools import combinations


def main():
    attendees, _ = read_numbers()
    binaries = read_binaries(attendees)
    print(*acm_team(binaries), sep='\n')


def read_numbers():
    return list(map(int, input().split()))


def read_binaries(n):
    return [input().strip() for _ in range(n)]


def acm_team(binaries):
    max_subjects = 0
    teams_with_max = 0

    for i, j in combinations(range(len(binaries)), 2):
        known_subjects = count_subjects_known_by_2_teams(binaries[i], binaries[j])

        if known_subjects > max_subjects:
            max_subjects = known_subjects
            teams_with_max = 1
        elif known_subjects == max_subjects:
            teams_with_max += 1

    return max_subjects, teams_with_max


def count_subjects_known_by_2_teams(a, b):
    return (int(a, 2) | int(b, 2)).bit_count()


if __name__ == '__main__':
    main()
