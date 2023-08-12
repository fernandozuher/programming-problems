# https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true#!/bin/ruby

def main():

    n = int(input())
    max_ones, ones = 0, 0

    while n > 0:
        if n % 2 == 1:
            ones += 1
        else:
            max_ones = max(max_ones, ones)
            ones = 0
        n = int(n/2)

    max_ones = max(max_ones, ones)
    print(max_ones)


if __name__ == "__main__":
    main()
