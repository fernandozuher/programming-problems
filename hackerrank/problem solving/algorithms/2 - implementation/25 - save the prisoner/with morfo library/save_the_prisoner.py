# https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

import morfo


def main():
    n = morfo.read(int)
    for i in range(n):
        prisoners = morfo.read(int)
        sweets = morfo.read(int)
        start_chair = morfo.read(int)
        print(save_the_prisoner(prisoners, sweets, start_chair))


# T: O(1)
# S: O(1) extra space
def save_the_prisoner(prisoners, sweets, start_chair):
    return ((start_chair - 1 + sweets - 1) % prisoners) + 1


if __name__ == '__main__':
    main()
