#!/bin/python3

#
# Complete the "staircase" function below.
#
# The function accepts INTEGER n as parameter.
#

def staircase(n):
    for i in range(1, n+1):
        for _ in range(n - i):
            print(" ", end = "")
        for _ in range(i):
            print("#", end = "")
        print("")


if __name__ == "__main__":
    n = int(input().strip())
    staircase(n)
