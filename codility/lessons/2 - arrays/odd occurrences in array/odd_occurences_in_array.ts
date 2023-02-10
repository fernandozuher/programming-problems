// Source: https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array/

function solution(A: number[]): number {
    A.sort((a, b) => a - b)
    let unpairedElement: number = A[0];
    let isElementPaired: boolean = false;

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
