# https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem?isFullScreen=true

s = input()
try:
    print(int(s))
except ValueError:
    print("Bad String")
