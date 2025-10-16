# https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

def main():
    n = int(input())
    for _ in range(n):
        money, cost, wrappers_needed = read_numbers()
        print(how_many_chocolates_can_be_eaten(money, cost, wrappers_needed))


def read_numbers():
    return list(map(int, input().split()))


def how_many_chocolates_can_be_eaten(money, cost, wrappers_needed):
    chocolates = money // cost
    wrappers = chocolates

    while wrappers >= wrappers_needed:
        free_chocolates = wrappers // wrappers_needed
        wrappers = wrappers % wrappers_needed + free_chocolates
        chocolates += free_chocolates

    return chocolates


if __name__ == '__main__':
    main()
