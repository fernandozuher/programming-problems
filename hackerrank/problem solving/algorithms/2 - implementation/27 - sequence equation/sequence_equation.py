# https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

def main():

    n = int(input())
    array = read_int_array()
    obj = SequenceEquation(array)
    print(*obj.permutated_array(), sep='\n')


def read_int_array():

    return list(map(int, input().split()))


class SequenceEquation:

    def __init__(self, array):

        self._array = array
        self._elements_positions_array = [None] * len(array)
        self._permutated_array = [None] * len(array)
        self._generate_elements_positions_array()
        self._generate_permutated_array()


    def _generate_elements_positions_array(self):

        for i, element in enumerate(self._array):
            self._elements_positions_array[element-1] = i


    def _generate_permutated_array(self):

        for i, element in enumerate(self._elements_positions_array):
            self._permutated_array[i] = self._elements_positions_array[element] + 1


    def permutated_array(self):

        return self._permutated_array


if __name__ == '__main__':
    main()
