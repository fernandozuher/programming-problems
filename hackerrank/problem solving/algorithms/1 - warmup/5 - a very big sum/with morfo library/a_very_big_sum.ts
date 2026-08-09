// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

import { readLn, skipInputLn, sum } from 'morfo';

skipInputLn();
const arr: number[] = readLn(Number);
console.log(aVeryBigSum(arr));

// n: length of arr
// T: O(n)
// S: O(1) extra space
function aVeryBigSum(arr: number[]): number {
  return sum(arr);
}
