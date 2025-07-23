# https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

def main():
    _, max_jump = read_numbers()
    hurdles = read_numbers()
    print(hurdle_race(hurdles, max_jump))


def read_numbers():
    return list(map(int, input().split()))


def hurdle_race(hurdles, max_jump):
    return max(0, max(hurdles) - max_jump)


if __name__ == '__main__':
    main()
