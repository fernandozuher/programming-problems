// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

import { read } from 'morfo';

const n: number = read(Number);
const page: number = read(Number);
console.log(pageCount(n, page));

// T: O(1)
// S: O(1) extra space
function pageCount(n: number, page: number): number {
  const fromFront: number = Math.trunc(page / 2);
  const fromBack: number = Math.trunc(n / 2) - fromFront;
  return Math.min(fromFront, fromBack);
}
