# https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

def main():
    n = int(input())
    cycles = read_numbers(n)
    print(*utopian_tree(cycles), sep='\n')


def read_numbers(n):
    return [int(input()) for _ in range(n)]


def utopian_tree(cycles):
    return list(map(calculate_height, cycles))


def calculate_height(cycles):
    height = 1
    for cycle in range(1, cycles + 1):
        height = height * 2 if is_cycle_happening_during_spring(cycle) else height + 1
    return height


def is_cycle_happening_during_spring(cycle):
    return cycle & 1


if __name__ == '__main__':
    main()
