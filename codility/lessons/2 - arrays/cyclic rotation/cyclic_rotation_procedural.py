# Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

def solution(A, K):

    ROTATED_ARRAY = is_there_rotation(A, K)

    if ROTATED_ARRAY != None:
        return ROTATED_ARRAY
    else:
        return A


def is_there_rotation(array, rotation):

    NEW_ROTATION = reduce_rotations(len(array), rotation)

    if NEW_ROTATION > 0:
        ROTATED_ARRAY = rotate_elements(array, NEW_ROTATION)
        return ROTATED_ARRAY
    else:
        return None


def reduce_rotations(array_size, rotation):

    if array_size > 1:
        return rotation % array_size if rotation >= array_size else rotation
    else:
        return 0


def rotate_elements(array, rotation):

    return array[len(array) - rotation:] + array[:len(array) - rotation]
