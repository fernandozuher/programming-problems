// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

import { read } from 'morfo';

const n1 = read(Number);
const n2 = read(Number);
console.log(solveMeFirst(n1, n2));

// T: O(1)
// S: O(1) extra space
function solveMeFirst(n1, n2) {
  return n1 + n2;
}
