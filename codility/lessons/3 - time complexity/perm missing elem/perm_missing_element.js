// Source: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

function solution(array) {
    array.sort((a, b) => a - b);
    const MISSING_ELEMENT = findMissingElement(array);
    return MISSING_ELEMENT;
}

    function findMissingElement(array) {
        let i;

        for (i = 0; i < array.length; i++)
            if (array[i] !== i + 1)
                break;

        return i + 1;
    }
