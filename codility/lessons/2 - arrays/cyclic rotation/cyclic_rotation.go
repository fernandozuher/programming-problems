// Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

package solution


func Solution(A []int, K int) []int {
    var rotated_array []int = isThereRotation(A, K)

    if rotated_array != nil {
        return rotated_array
    } else {
        return A
    }
}

    func isThereRotation(array []int, rotation int) []int {
        var new_rotation int = reduceRotations(len(array), rotation)

        if new_rotation > 0 {
            var rotated_array []int = rotateElements(array, new_rotation)
            return rotated_array
        } else {
            return nil
        }
    }

        func reduceRotations(array_size int, rotation int) int {
            if array_size > 1 {
                if rotation >= array_size {
                    return rotation % array_size
                } else {
                    return rotation
                }
            } else {
                return 0
            }
        }

        func rotateElements(array []int, rotation int) []int {
            var new_array []int = append(array[len(array)-rotation:], array[:len(array)-rotation]...)
            return new_array
        }
