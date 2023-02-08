// Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

function solution(A: number[], K: number): number[] {
    const ROTATED_ARRAY: number[] = isThereRotation(A, K);

    if (ROTATED_ARRAY != null)
        return ROTATED_ARRAY;
    else
        return A;
}

    function isThereRotation(array: number[], rotation: number): number[] {
        const NEW_ROTATION: number = reduceRotations(array.length, rotation);

        if (NEW_ROTATION > 0) {
            const ROTATED_ARRAY: number[] = rotateElements(array, NEW_ROTATION);
            return ROTATED_ARRAY;
        } else
            return null;
    }

        function reduceRotations(array_size: number, rotation: number): number {
            if (array_size > 1)
                return rotation >= array_size ? rotation % array_size : rotation;
            else
                return 0
        }

        function rotateElements(array: number[], rotation: number): number[] {
            const NEW_ARRAY: number[] = [...array.slice(array.length-rotation, array.length), ...array.slice(0, array.length-rotation)];
            return NEW_ARRAY;
        }
