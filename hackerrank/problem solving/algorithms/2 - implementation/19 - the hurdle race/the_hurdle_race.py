# https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

def main():
    _, max_jump = read_nums()
    hurdles = read_nums()
    print(hurdle_race(hurdles, max_jump))


def read_nums():
    return list(map(int, input().split()))


# n: length of hurdles
# T: O(n)
# S: O(1) extra space
def hurdle_race(hurdles, max_jump):
    return max(0, max(hurdles) - max_jump)


if __name__ == '__main__':
    main()
