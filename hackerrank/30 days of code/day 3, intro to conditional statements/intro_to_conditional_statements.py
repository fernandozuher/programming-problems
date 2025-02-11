# https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true

n = int(input())
is_weird = n & 1 or n >= 6 and n <= 20
print('Weird' if is_weird else 'Not Weird')
