# Source: https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

def main():

    NUMBER = int(input())
    FACTORIAL = calculateFactorialOf(NUMBER)
    print(FACTORIAL)


def calculateFactorialOf(number):

    factorial = 1
    for i in range(2, number+1):
        factorial *= i
    return factorial


if __name__ == "__main__":
    main()
