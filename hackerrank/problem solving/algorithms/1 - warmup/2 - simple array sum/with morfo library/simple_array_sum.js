// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

import { skipInputLn, readLn, sum } from 'morfo';

skipInputLn();
console.log(sumStdin());

// n: number of integers in the input line
// T: O(n)
// S: O(n) extra space
function sumStdin() {
  return sum(readLn(Number));
}
