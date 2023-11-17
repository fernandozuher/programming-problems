# https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

def main():

    n = int(input())
    array = list(map(int, input().split()))
    plus_minus(array)


def plus_minus(array):

    positive_quantity, negative_quantity, zero_quantity = 0, 0, 0

    for number in array:
        if number > 0:
            positive_quantity += 1
        elif number < 0:
            negative_quantity += 1
        else:
            zero_quantity += 1

    n = len(array)
    positive_values_proportion = float(positive_quantity / n)
    negative_values_proportion = float(negative_quantity / n)
    zero_values_proportion = float(zero_quantity / n)
    
    print("%.6f" % positive_values_proportion)
    print("%.6f" % negative_values_proportion)
    print("%.6f" % zero_values_proportion)


if __name__ == '__main__':
    main()
