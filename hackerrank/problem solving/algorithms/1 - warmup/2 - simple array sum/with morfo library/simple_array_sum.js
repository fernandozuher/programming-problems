// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

import { skipInputLn, readLn } from 'morfo';

skipInputLn();
console.log(sumStdin());

// n: number of integers in the input line
// T: O(n)
// S: O(n) extra space
function sumStdin() {
  return readLn(Number).reduce((acc, x) => acc + x, 0);
}
