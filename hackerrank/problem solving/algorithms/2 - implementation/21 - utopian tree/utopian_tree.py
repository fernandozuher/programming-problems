# https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

def main():

    n = int(input())
    test_cases = read_lines(n)
    obj = UtopianTree(test_cases)
    print(*obj.trees_heights(), sep='\n')


def read_lines(n):

    return [int(input()) for _ in range(n)]


class UtopianTree:

    def __init__(self, test_cases):

        self._test_cases = test_cases
        self._trees_heights = [None] * len(test_cases)
        self._calculate_trees_heights()


    def _calculate_trees_heights(self):

        for i in range(len(self._trees_heights)):
            self._trees_heights[i] = self._calculate_height(self._test_cases[i])


    def _calculate_height(self, cycles):

        height = 1
        for cycle in range(1, cycles+1):
            height = height * 2 if self._is_cycle_happening_during_spring(cycle) else height + 1
        return height


    def _is_cycle_happening_during_spring(self, cycle):

        return cycle & 1


    def trees_heights(self):

        return self._trees_heights


if __name__ == "__main__":
    main()
