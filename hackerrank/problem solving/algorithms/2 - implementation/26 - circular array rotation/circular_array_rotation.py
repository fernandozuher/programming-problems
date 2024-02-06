# https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

def main():

    _, rotation_count, n_queries = read_int_array()
    array = read_int_array()
    queries = read_lines(n_queries)

    obj = CircularArrayRotation(array, rotation_count)
    print_array_according_to_index_from_another_array(obj.rotated_array(), queries)


def read_int_array():

    return list(map(int, input().split()))


def read_lines(n):

    return [int(input()) for _ in range(n)]


def print_array_according_to_index_from_another_array(array1, array2):

    [print(array1[i]) for i in array2]


class CircularArrayRotation:

    def __init__(self, array, rotation_count):

        self._array = array
        self._rotation_count = rotation_count
        self._reduce_rotations()
        self._rotate_array()


    def _reduce_rotations(self):

        if (len(self._array) > 1):
            self._rotation_count = self._rotation_count % len(self._array) if self._rotation_count >= len(self._array) else self._rotation_count
        else:
            self._rotation_count = 0


    def _rotate_array(self):

        first_part_new_array = self._array[len(self._array) - self._rotation_count:]
        second_part_new_array = self._array[:len(self._array) - self._rotation_count]
        self._array = first_part_new_array + second_part_new_array


    def rotated_array(self):

        return self._array


if __name__ == '__main__':
    main()
