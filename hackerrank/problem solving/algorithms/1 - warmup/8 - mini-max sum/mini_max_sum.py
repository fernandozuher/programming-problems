#!/bin/python3

#
# Complete the 'miniMaxSum' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def miniMaxSum(arr):
    arr = sorted(arr)
    totalSum = sum(arr)
    minSum = totalSum - arr[-1]
    maxSum = totalSum - arr[0]
    print(f"{minSum} {maxSum}")

if __name__ == '__main__':
    arr = list(map(int, input().rstrip().split()))
    miniMaxSum(arr)
