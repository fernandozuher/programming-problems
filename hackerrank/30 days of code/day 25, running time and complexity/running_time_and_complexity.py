# https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

import math

def main():

    n = int(input())
    for _ in range(n):
        number = int(input())

        if number == 1:
            print("Not prime")
            continue

        i, limit = 2, math.sqrt(number)
        while i <= limit:
            if not (number % i):
                print("Not prime")
                break
            i += 1

        if i > limit:
            print("Prime")


if __name__ == '__main__':
    main()
