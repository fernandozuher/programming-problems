# https://www.hackerrank.com/challenges/30-scope/problem?isFullScreen=true

class Difference:

    def __init__(self, elements):

        self._elements = elements
        self.maximum_difference = 0


    def compute_difference(self):

        self._elements.sort()
        self.maximum_difference = self._elements[-1] - self._elements[0]


def main():

    _ = int(input()) # _ (n) not used
    ARRAY = list(map(int, input().split()))

    DIFFERENCE = Difference(ARRAY)
    DIFFERENCE.compute_difference()
    print(DIFFERENCE.maximum_difference)


if __name__ == '__main__':
    main()
