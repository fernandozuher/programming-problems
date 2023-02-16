// Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

function solution(array: number[]): number {
    const MINIMUM_DIFFERENCE_BETWEEN_PARTS: number = findMinimumDifferenceBetweenTwoPartsArray(array);
    return MINIMUM_DIFFERENCE_BETWEEN_PARTS;
}

    function findMinimumDifferenceBetweenTwoPartsArray(array: number[]): number {
        let firstPart: number = array[0];
        let secondPart: number = sumArrayElements(array) - firstPart;
        let minimumDifferenceBetweenParts: number = Math.abs(firstPart - secondPart);

        for (let i = 1, size = array.length - 1; i < size; i++) {
            firstPart += array[i];
            secondPart -= array[i];
            const CURRENT_MINIMUM: number = Math.abs(firstPart - secondPart);

            if (minimumDifferenceBetweenParts > CURRENT_MINIMUM)
                minimumDifferenceBetweenParts = CURRENT_MINIMUM;
        }

        return minimumDifferenceBetweenParts;
    }

        function sumArrayElements(array: number[]): number {
            return array.reduce((a, b) => a + b);
        }
