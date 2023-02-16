// Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

function solution(array) {
    const MINIMUM_DIFFERENCE_BETWEEN_PARTS = findMinimumDifferenceBetweenTwoPartsArray(array);
    return MINIMUM_DIFFERENCE_BETWEEN_PARTS;
}

    function findMinimumDifferenceBetweenTwoPartsArray(array) {
        let firstPart = array[0];
        let secondPart = sumArrayElements(array) - firstPart;
        let minimumDifferenceBetweenParts = Math.abs(firstPart - secondPart);

        for (i = 1, size = array.length - 1; i < size; i++) {
            firstPart += array[i];
            secondPart -= array[i];
            const CURRENT_MINIMUM = Math.abs(firstPart - secondPart);

            if (minimumDifferenceBetweenParts > CURRENT_MINIMUM)
                minimumDifferenceBetweenParts = CURRENT_MINIMUM;
        }

        return minimumDifferenceBetweenParts;
    }

        function sumArrayElements(array) {
            return array.reduce((a, b) => a + b);
        }
