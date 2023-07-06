# Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

def solution(a, k)
    rotated_array = rotation?(a, k)

    if rotated_array != nil
        rotated_array
    else
        a
    end
end

    def rotation?(array, rotation)
        new_rotation = reduce_rotations(array.size, rotation)

        if new_rotation > 0
            rotated_array = rotate_elements(array, new_rotation)
        else
            nil
        end
    end

        def reduce_rotations(array_size, rotation)
            if array_size > 1
                rotation >= array_size ? rotation % array_size : rotation
            else
                0
            end
        end

        def rotate_elements(array, rotation)
            array[array.size - rotation...] + array[...array.size - rotation]
        end
