# Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

def solution(A, K):

    ROTATED_ARRAY = isThereRotation(A, K)

    if ROTATED_ARRAY != None:
        return ROTATED_ARRAY
    else:
        return A


def isThereRotation(array, rotation):

    NEW_ROTATION = reduceRotations(len(array), rotation)

    if NEW_ROTATION > 0:
        ROTATED_ARRAY = rotateElements(array, NEW_ROTATION)
        return ROTATED_ARRAY
    else:
        return None


def reduceRotations(array_size, rotation):

    if array_size > 1:
        return rotation % array_size if rotation >= array_size else rotation
    else:
        return 0


def rotateElements(array, rotation):

    NEW_ARRAY = array[len(array) - rotation:] + array[:len(array) - rotation]
    return NEW_ARRAY
