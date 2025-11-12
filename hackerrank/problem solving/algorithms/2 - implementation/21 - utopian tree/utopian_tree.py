# https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

def main():
    n = int(input())
    for _ in range(n):
        cycles = int(input())
        print(utopian_tree(cycles))


def utopian_tree(cycles):
    height = 1
    for cycle in range(1, cycles + 1):
        height = height * 2 if is_cycle_happening_during_spring(cycle) else height + 1
    return height


def is_cycle_happening_during_spring(cycle):
    return cycle & 1


if __name__ == '__main__':
    main()
