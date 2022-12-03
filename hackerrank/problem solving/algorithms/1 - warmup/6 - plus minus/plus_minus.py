#!/bin/python3

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    positiveQuantity, negativeQuantity, zeroQuantity = 0, 0, 0

    for number in arr:
        if number > 0:
            positiveQuantity += 1
        elif number < 0:
            negativeQuantity += 1
        else:
            zeroQuantity += 1

    n = len(arr)
    positiveValuesProportion = float(positiveQuantity / n)
    negativeValuesProportion = float(negativeQuantity / n)
    zeroValuesProportion = float(zeroQuantity / n)
    
    print("%.6f" % positiveValuesProportion)
    print("%.6f" % negativeValuesProportion)
    print("%.6f" % zeroValuesProportion)

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
