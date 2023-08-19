# https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true

n = int(input())

if n & 1 or n >= 6 and n <= 20:
    print('Weird')
else:
    print('Not Weird')
