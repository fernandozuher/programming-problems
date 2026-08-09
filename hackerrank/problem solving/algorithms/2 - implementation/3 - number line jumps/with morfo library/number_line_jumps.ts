// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

import { read } from 'morfo';

function main() {
  const initialState: number[] = read(4, Number);
  console.log(kangaroo(initialState) ? 'YES' : 'NO');
}

// T: O(1)
// S: O(1) extra space
function kangaroo(initialState: number[]): boolean {
  const [x1, v1, x2, v2]: number[] = initialState;

  if (v1 === v2) return x1 === x2;

  const distanceDiff = x2 - x1;
  const velocityDiff = v1 - v2;
  return distanceDiff * velocityDiff >= 0 && distanceDiff % velocityDiff === 0;
}

main();
