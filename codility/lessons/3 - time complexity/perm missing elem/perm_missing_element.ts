// Source: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

function solution(array: number[]): number {
    array.sort((a, b) => a - b);
    const MISSING_ELEMENT: number = findMissingElement(array);
    return MISSING_ELEMENT;
}

    function findMissingElement(array: number[]): number {
        let i: number;

        for (i = 0; i < array.length; i++)
            if (array[i] !== i + 1)
                break;

        return i + 1;
    }
