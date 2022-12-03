import math

N = int(input())

for _ in range(N):
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
