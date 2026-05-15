// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}

//////////////////////////////////////////////////

function main() {
  const initialState: number[] = readNumbers();
  console.log(kangaroo(initialState) ? 'YES' : 'NO');
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
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
