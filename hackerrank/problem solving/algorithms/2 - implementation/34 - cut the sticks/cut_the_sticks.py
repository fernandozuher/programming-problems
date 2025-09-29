# https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

def main():
    input()
    arr = sorted(read_numbers())
    print(*cut_the_sticks(arr), sep='\n')


def read_numbers():
    return list(map(int, input().split()))


def cut_the_sticks(arr):
    res = []
    i = 0
    n = len(arr)
    while i < n:
        res.append(n - i)
        shortest = arr[i]
        while i < n and arr[i] == shortest:
            i += 1
    return res


if __name__ == '__main__':
    main()
