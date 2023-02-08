# Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

def solution a, k
    rotatedArray = isThereRotation a, k

    if rotatedArray != nil
        rotatedArray
    else
        a
    end
end

    def isThereRotation array, rotation
        newRotation = reduceRotations array.size, rotation

        if newRotation > 0
            rotatedArray = rotateElements array, newRotation
        else
            nil
        end
    end

        def reduceRotations arraySize, rotation
            if arraySize > 1
                rotation >= arraySize ? rotation % arraySize : rotation
            else
                0
            end
        end

        def rotateElements(array, rotation)
            newArray = array[array.size - rotation...] + array[...array.size - rotation]
        end
