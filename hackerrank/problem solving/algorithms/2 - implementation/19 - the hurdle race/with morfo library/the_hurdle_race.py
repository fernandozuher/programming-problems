# https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

import morfo


def main():
    morfo.skip_input()
    max_jump = morfo.read(int)
    hurdles = morfo.readln(int, list)
    print(hurdle_race(hurdles, max_jump))


# n: length of hurdles
# T: O(n)
# S: O(1) extra space
def hurdle_race(hurdles, max_jump):
    return max(0, max(hurdles) - max_jump)


if __name__ == '__main__':
    main()
