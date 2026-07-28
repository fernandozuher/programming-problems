// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

import { readLn, skipInputLn } from 'morfo';

skipInputLn();
const arr = readLn(Number);
console.log(aVeryBigSum(arr));

// n: length of arr
// T: O(n)
// S: O(1) extra space
function aVeryBigSum(arr) {
  return arr.reduce((a, b) => a + b);
}
