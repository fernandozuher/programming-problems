# https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

import morfo


def main():
    n = morfo.read(int)
    for _ in range(n):
        money, cost, wrappers_needed = morfo.readln(int, list)
        print(how_many_chocolates_can_be_eaten(money, cost, wrappers_needed))


# T: O(log(money / cost))
# S: O(1) extra space
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
