# https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

input()
arr = list(map(int, input().split()))
arr.reverse()
print(*arr, sep=' ')
