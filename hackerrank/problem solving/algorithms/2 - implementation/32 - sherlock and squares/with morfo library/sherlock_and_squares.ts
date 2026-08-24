// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

import { read } from 'morfo';

const n: number = read(Number);
for (let i = 0; i < n; i++) {
  const [a, b]: [number, number] = read(Number, Number);
  console.log(squares(a, b));
}

// T: O(1)
// S: O(1) extra space
function squares(startNum: number, endNum: number): number {
  const minSquare: number = Math.ceil(Math.sqrt(startNum));
  const maxSquare: number = Math.floor(Math.sqrt(endNum));
  return maxSquare - minSquare + 1;
}
