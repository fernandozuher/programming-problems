# https://www.hackerrank.com/challenges/30-scope/problem?isFullScreen=true

def main():
    input()  # Size not used
    numbers = list(map(int, input().split()))
    difference = Difference(numbers)
    difference.compute_difference()
    print(difference.maximum_difference)


class Difference:

    def __init__(self, elements):
        self.__elements = elements
        self.maximum_difference = 0

    def compute_difference(self):
        self.maximum_difference = max(self.__elements) - min(self.__elements)


if __name__ == '__main__':
    main()
