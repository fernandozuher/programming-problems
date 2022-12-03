#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'diagonalDifference' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def diagonalDifference(arr):
    primaryDiagonal, secondaryDiagonal = 0, 0
    primaryDiagonalRange = range(len(arr))
    secondaryDiagonalRange = range(len(arr)-1, -1, -1)
    
    for i, j in zip(primaryDiagonalRange, secondaryDiagonalRange):
        primaryDiagonal += arr[j][j]
        secondaryDiagonal += arr[j][i]
    
    return abs(primaryDiagonal - secondaryDiagonal)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
