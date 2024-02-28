# https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

def main():

    n = int(input())
    array = read_int_array()
    array.sort()

    obj = CutTheSticks(array)
    print(*obj.remaining_sticks_length_array(), sep='\n')


def read_int_array():

    return list(map(int, input().split()))


class CutTheSticks:

    def __init__(self, array):

        self._sticks_length_array = array
        self._remaining_sticks_length_array = [len(array)]
        self._cut_the_sticks()


    def _cut_the_sticks(self):

        n = len(self._sticks_length_array)
        i = 0

        while i < n:
            shortest_stick_length = self._sticks_length_array[i]

            i = self._find_first_element_index_different_of_first_current_shortest_stick_length_index(i, n)
            current_iterationn = n - i
            if i == n:
                break

            self._remaining_sticks_length_array.append(current_iterationn)
            self._decrease_sticks_lengths_higher_than_current_shortest_stick_length(i, n, shortest_stick_length)


    def _find_first_element_index_different_of_first_current_shortest_stick_length_index(self, index, n):

        shortest_stick_length = self._sticks_length_array[index]
        while index < n and self._sticks_length_array[index] == shortest_stick_length:
            index += 1
        return index


    def _decrease_sticks_lengths_higher_than_current_shortest_stick_length(self, index, n, shortest_stick_length):

        for i in range(index, n):
            self._sticks_length_array[i] -= shortest_stick_length


    def remaining_sticks_length_array(self):

        return self._remaining_sticks_length_array


if __name__ == '__main__':
    main()
