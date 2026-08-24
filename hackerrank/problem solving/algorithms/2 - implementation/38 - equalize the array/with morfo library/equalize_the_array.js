// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

import { counter, max, readLn, skipInputLn } from 'morfo';

skipInputLn();
console.log(minDeletionsToEqualize(readLn(Number)));

// n: length of arr, 1 <= n <= 100
// k: number of distinct elements in arr
// k <= n
// T: O(n) = O(100) = O(1)
// S: O(k) = O(n) = O(100) = O(1) extra space
function minDeletionsToEqualize(arr) {
  return arr.length - max(counter(arr).values());
}
