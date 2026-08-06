// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

import { readLn, reduceMany } from 'morfo';

const arr = readLn(Number);
const [minSum, maxSum] = calcMinMaxSum(arr);
console.log(minSum, maxSum);

// n: length of arr
// T: O(n)
// S: O(1) extra space
function calcMinMaxSum(arr) {
  const [total, minValue, maxValue] = reduceMany(
    arr,
    (a, v) => a + v,
    0,
    Math.min,
    arr[0],
    Math.max,
    arr[0],
  );

  return [total - maxValue, total - minValue];
}
