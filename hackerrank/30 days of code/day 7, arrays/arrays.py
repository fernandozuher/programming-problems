# https://www.hackerrank.com/challenges/30-arrays/problem?isFullScreen=true

n = int(input())
array = list(map(int, input().split()))
print(*reversed(array), sep=' ')
