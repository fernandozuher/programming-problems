# https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

def main():
    input()
    print(minimum_number_of_jumps(read_numbers()))


def read_numbers():
    return list(map(int, input().split()))


def minimum_number_of_jumps(clouds):
    i = 0
    n = len(clouds) - 1
    jumps = 0

    while i < n:
        i += next_jump(i, clouds)
        jumps += 1
    return jumps


def next_jump(index, clouds):
    if index + 2 < len(clouds):
        if is_next_second_cloud_cumulus := clouds[index + 2] == 0:
            return 2
    return 1


if __name__ == '__main__':
    main()
