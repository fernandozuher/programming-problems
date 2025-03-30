# https://www.hackerrank.com/challenges/30-interfaces/problem?isFullScreen=true

from abc import ABC, abstractmethod
from typing_extensions import override


def main():
    n = int(input())
    calc = Calculator()
    print("I implemented: " + type(calc).__bases__[0].__name__)
    print(calc.divisor_sum(n))


class AdvancedArithmetic(ABC):

    @abstractmethod
    def divisor_sum(self, n):
        pass


class Calculator(AdvancedArithmetic):

    @override
    def divisor_sum(self, n):
        sum = 0
        for i in range(1, int(n / 2) + 1):
            if is_divisible_by(n, i):
                sum += i
        return sum + n


def is_divisible_by(n, i):
    return n % i == 0


if __name__ == '__main__':
    main()
