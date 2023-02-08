// Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

function solution(A, K) {
    const ROTATED_ARRAY = isThereRotation(A, K);

    if (ROTATED_ARRAY != null)
        return ROTATED_ARRAY;
    else
        return A;
}

    function isThereRotation(array, rotation) {
        const NEW_ROTATION = reduceRotations(array.length, rotation);

        if (NEW_ROTATION > 0) {
            const ROTATED_ARRAY = rotateElements(array, NEW_ROTATION);
            return ROTATED_ARRAY;
        } else
            return null;
    }

        function reduceRotations(array_size, rotation) {
            if (array_size > 1)
                return rotation >= array_size ? rotation % array_size : rotation;
            else
                return 0
        }

        function rotateElements(array, rotation) {
            const NEW_ARRAY = [...array.slice(array.length-rotation, array.length), ...array.slice(0, array.length-rotation)];
            return NEW_ARRAY;
        }
