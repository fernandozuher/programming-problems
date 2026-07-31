// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

import { readLn } from 'morfo';

const arr = readLn(Number);
const [minSum, maxSum] = calcMinMaxSum(arr);
console.log(minSum, maxSum);

// n: length of arr
// T: O(n)
// S: O(1) extra space
function calcMinMaxSum(arr) {
  let total, minValue, maxValue;
  total = minValue = maxValue = arr[0];

  for (let i = 1; i < arr.length; i++) {
    total += arr[i];
    minValue = Math.min(minValue, arr[i]);
    maxValue = Math.max(maxValue, arr[i]);
  }

  return [total - maxValue, total - minValue];
}
