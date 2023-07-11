// Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

function solution(array: number[]): number {
    let firstPart: number = array[0];
    let secondPart: number = sumArrayElements(array) - firstPart;
    let minimumDifferenceBetweenParts: number = Math.abs(firstPart - secondPart);

    for (let element of array.slice(1, -1)) {
        firstPart += element;
        secondPart -= element;
        const CURRENT_MINIMUM: number = Math.abs(firstPart - secondPart);
        minimumDifferenceBetweenParts = Math.min(minimumDifferenceBetweenParts, CURRENT_MINIMUM);
    }

    return minimumDifferenceBetweenParts;
}

    function sumArrayElements(array: number[]): number {
        return array.reduce((a, b) => a + b, 0);
    }
