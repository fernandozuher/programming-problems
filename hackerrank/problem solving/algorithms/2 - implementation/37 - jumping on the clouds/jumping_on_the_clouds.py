# https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

def main():
    input()
    print(min_jumps(read_numbers()))


def read_numbers():
    return list(map(int, input().split()))


# n: length of array clouds
# T: O(n)
# S: O(1) extra space
def min_jumps(clouds):
    i = 0
    n = len(clouds) - 1
    jumps = 0

    while i < n:
        i += skip(i, clouds)
        jumps += 1
    return jumps


def skip(idx, clouds):
    return 2 if is_next_second_cloud_cumulus(idx, clouds) else 1


def is_next_second_cloud_cumulus(idx, clouds):
    return idx + 2 < len(clouds) and clouds[idx + 2] == 0


if __name__ == '__main__':
    main()
