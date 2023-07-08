// Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

package solution

func Solution(A []int, K int) []int {
    var rotatedSlice []int = isThereRotation(A, K)

    if rotatedSlice != nil {
        return rotatedSlice
    } else {
        return A
    }
}

    func isThereRotation(slice []int, rotation int) []int {
        var newRotation int = reduceRotations(len(slice), rotation)

        if newRotation > 0 {
            var rotatedSlice []int = rotateElements(slice, newRotation)
            return rotatedSlice
        } else {
            return nil
        }
    }

        func reduceRotations(sliceSize int, rotation int) int {
            if sliceSize > 1 {
                if rotation >= sliceSize {
                    return rotation % sliceSize
                } else {
                    return rotation
                }
            } else {
                return 0
            }
        }

        func rotateElements(slice []int, rotation int) []int {
            return append(slice[len(slice)-rotation:], slice[:len(slice)-rotation]...)
        }
