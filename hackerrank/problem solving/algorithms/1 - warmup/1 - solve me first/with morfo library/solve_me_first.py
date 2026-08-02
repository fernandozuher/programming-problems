# https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

import morfo


def main():
    n1 = morfo.read(int)
    n2 = morfo.read(int)
    print(solve_me_first(n1, n2))


# T: O(1)
# S: O(1) extra space
def solve_me_first(n1, n2):
    return n1 + n2


if __name__ == '__main__':
    main()
