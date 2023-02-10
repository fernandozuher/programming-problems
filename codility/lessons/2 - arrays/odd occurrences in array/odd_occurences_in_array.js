// Source: https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

function solution(A) {
    A.sort((a, b) => a - b)
    let unpairedElement = A[0];
    let isElementPaired = false;

    for (let i = 1, N = A.length; i < N; i++)
        if (A[i] === unpairedElement)
            isElementPaired = !isElementPaired;
        else if (isElementPaired) {
            isElementPaired = false;
            unpairedElement = A[i];
        }
        else
            break;
    
    return unpairedElement;
}
