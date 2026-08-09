// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

import { read } from 'morfo';

function main() {
  const n: number = read(Number);
  for (let i = 0; i < n; i++) {
    const a: number = read(Number);
    const b: number = read(Number);
    console.log(squares(a, b));
  }
}

// T: O(1)
// S: O(1) extra space
function squares(startNum: number, endNum: number): number {
  const minSquare: number = Math.ceil(Math.sqrt(startNum));
  const maxSquare: number = Math.floor(Math.sqrt(endNum));
  return maxSquare - minSquare + 1;
}

main();
