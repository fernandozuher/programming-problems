# Source: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

#!/bin/python3

import os

#
# Complete the 'kangaroo' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. INTEGER x1
#  2. INTEGER v1
#  3. INTEGER x2
#  4. INTEGER v2
#

def kangaroo(x1, v1, x2, v2):

    if v2 >= v1:
        return "NO"
    while x1 < x2:
        x1 += v1
        x2 += v2
    return "YES" if x1 == x2 else "NO"


if __name__ == '__main__':

    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    numbers = list(map(int, input().split()))
    x1 = numbers[0]
    v1 = numbers[1]
    x2 = numbers[2]
    v2 = numbers[3]

    result = kangaroo(x1, v1, x2, v2)
    fptr.write(result + '\n')
    
    fptr.close()
