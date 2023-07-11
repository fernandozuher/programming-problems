// Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

function solution(array) {
    let firstPart = array[0];
    let secondPart = sumArrayElements(array) - firstPart;
    let minimumDifferenceBetweenParts = Math.abs(firstPart - secondPart);

    for (let element of array.slice(1, -1)) {
        firstPart += element;
        secondPart -= element;
        const CURRENT_MINIMUM = Math.abs(firstPart - secondPart);
        minimumDifferenceBetweenParts = Math.min(minimumDifferenceBetweenParts, CURRENT_MINIMUM);
    }

    return minimumDifferenceBetweenParts;
}

    function sumArrayElements(array) {
        return array.reduce((a, b) => a + b, 0);
    }
