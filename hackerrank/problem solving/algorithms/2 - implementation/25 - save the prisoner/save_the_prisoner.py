# https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

def main():
    n = int(input())
    results = [None] * n

    for i in range(n):
        prisoners, sweets, start_chair = read_numbers()
        results[i] = save_the_prisoner(prisoners, sweets, start_chair)

    print(*results, sep='\n')


def read_numbers():
    return list(map(int, input().split()))


def save_the_prisoner(prisoners, sweets, start_chair):
    return ((start_chair - 1 + sweets - 1) % prisoners) + 1


if __name__ == '__main__':
    main()
