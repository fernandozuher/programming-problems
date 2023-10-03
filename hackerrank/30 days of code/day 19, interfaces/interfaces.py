# https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

def main():
    
    n = int(input())
    calc = Calculator()
    print("I implemented: " + type(calc).__bases__[0].__name__)
    print(calc.divisorSum(n))


class AdvancedArithmetic(object):

    def divisorSum(n):

        raise NotImplementedError


class Calculator(AdvancedArithmetic):

    def divisorSum(self, n):

        sum = 0
        for i in range(1, int(n / 2) + 1):
            if not (n % i):
                sum += i
        return sum + n


if __name__ == '__main__':
    main()
