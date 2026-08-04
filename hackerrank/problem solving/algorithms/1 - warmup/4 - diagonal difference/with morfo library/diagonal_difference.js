// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

import { read, readLn } from 'morfo';

const n = read(Number);
console.log(diagonalDifference(n));

// T: O(n^2)
// S: O(n) extra space
function diagonalDifference(n) {
  let [primarySum, secondarySum] = [0, 0];

  for (let i = 0; i < n; i++) {
    const arr = readLn(Number);
    primarySum += arr[i];
    secondarySum += arr.at(-i - 1);
  }

  return Math.abs(primarySum - secondarySum);
}
