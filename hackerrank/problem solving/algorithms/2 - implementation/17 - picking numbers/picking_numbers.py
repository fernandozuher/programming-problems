# https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

def main():

    n = int(input())
    array = read_int_array()
    array.sort()

    obj = PickingNumbers(array)
    print(obj.subarray_biggest_size())


def read_int_array():

    return list(map(int, input().split()))


class PickingNumbers:

    def __init__(self, numbers):

        self._numbers = numbers
        self._subarray_biggest_size = 1
        self._picking_numbers()


    def _picking_numbers(self):

        first_reference_number_index = 0
        second_reference_number_index = 0
        subarray_current_size = 1

        for i in range(1, len(self._numbers)):
            difference = self._numbers[i] - self._numbers[first_reference_number_index]

            match difference:
                case 0:
                    subarray_current_size += 1

                case 1:
                    subarray_current_size += 1
                    if self._numbers[second_reference_number_index] != self._numbers[i]:
                        second_reference_number_index = i

                case _:
                    self._subarray_biggest_size = self._update_subarray_biggest_size(subarray_current_size)
                    update = self._update_first_reference_number_index_and_subarray_current_size(i, second_reference_number_index)

                    first_reference_number_index = update[0]
                    second_reference_number_index = i
                    subarray_current_size = update[1]

        self._subarray_biggest_size = self._update_subarray_biggest_size(subarray_current_size)


    def _update_subarray_biggest_size(self, subarray_current_size):

        return max(subarray_current_size, self._subarray_biggest_size)


    def _update_first_reference_number_index_and_subarray_current_size(self, i, second_reference_number_index):

        first_reference_number_index, subarray_current_size = 0, 0

        if self._numbers[i] - self._numbers[second_reference_number_index] == 1:
            first_reference_number_index = second_reference_number_index
            subarray_current_size = i - second_reference_number_index + 1
        else:
            first_reference_number_index = i
            subarray_current_size = 1

        return [first_reference_number_index, subarray_current_size]


    def subarray_biggest_size(self):

        return self._subarray_biggest_size


if __name__ == '__main__':
    main()
