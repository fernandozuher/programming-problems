# https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

def main():

    n = int(input())
    array = list(map(int, input().split()))
    plus_minus(array)


def plus_minus(array):

    positive, negative, zero = 0, 0, 0

    for number in array:
        if number > 0:
            positive += 1
        elif number < 0:
            negative += 1
        else:
            zero += 1

    n = len(array)
    positive_proportion = float(positive / n)
    negative_proportion = float(negative / n)
    zero_proportion = float(zero / n)
    
    print("%.6f" % positive_proportion)
    print("%.6f" % negative_proportion)
    print("%.6f" % zero_proportion)


if __name__ == '__main__':
    main()
