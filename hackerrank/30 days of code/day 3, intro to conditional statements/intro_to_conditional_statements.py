# https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true

N = int(input())

if N & 1 or N >= 6 and N <= 20:
    print("Weird")
else:
    print("Not Weird")
