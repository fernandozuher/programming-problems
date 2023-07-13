// Source: https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/

function solution(array: number[]): number {
    array.sort((a, b) => a - b);
    let i: number;
    for (i = 0; i < array.length && array[i] === i + 1; i++);
    return i === array.length ? 1 : 0;
}
