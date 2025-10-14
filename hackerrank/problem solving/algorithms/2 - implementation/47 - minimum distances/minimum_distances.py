# https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

def main():
    input()
    arr = read_numbers()
    print(min_distance(arr))


def read_numbers():
    return list(map(int, input().split()))


def min_distance(arr):
    last_seen = {}
    min_dist = None

    for i, x in enumerate(arr):
        if x in last_seen:
            dist = i - last_seen[x]
            if min_dist is None or dist < min_dist:
                min_dist = dist
                if min_dist == 1:
                    return 1

        last_seen[x] = i

    return -1 if min_dist is None else min_dist


if __name__ == '__main__':
    main()
