// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

function main() {
  let n1: number = +readLine();
  let n2: number = +readLine();
  console.log(solveMeFirst(n1, n2));
}

// T: O(1)
// S: O(1) extra space
function solveMeFirst(n1: number, n2: number): number {
  return n1 + n2;
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
