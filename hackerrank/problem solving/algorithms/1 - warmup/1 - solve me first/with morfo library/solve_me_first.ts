// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

import { read } from 'morfo';

const n1: number = read(Number);
const n2: number = read(Number);
console.log(solveMeFirst(n1, n2));

// T: O(1)
// S: O(1) extra space
function solveMeFirst(n1: number, n2: number): number {
  return n1 + n2;
}
