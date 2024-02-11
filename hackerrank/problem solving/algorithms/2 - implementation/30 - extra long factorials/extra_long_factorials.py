# https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

def main():

    number = int(input())
    factorial = calculate_factorial_of(number)
    print(factorial)


def calculate_factorial_of(number):

    factorial = 1
    for current_number in range(2, number+1):
        factorial *= current_number
    return factorial


if __name__ == '__main__':
    main()
