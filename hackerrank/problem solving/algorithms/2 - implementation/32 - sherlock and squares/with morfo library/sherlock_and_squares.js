// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

import { read } from 'morfo';

function main() {
  const n = read(Number);
  for (let i = 0; i < n; i++) {
    const a = read(Number);
    const b = read(Number);
    console.log(squares(a, b));
  }
}

// T: O(1)
// S: O(1) extra space
function squares(startNum, endNum) {
  const minSquare = Math.ceil(Math.sqrt(startNum));
  const maxSquare = Math.floor(Math.sqrt(endNum));
  return maxSquare - minSquare + 1;
}

main();
