// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

function main() {
  const n: number = +readLine();
  const page: number = +readLine();
  console.log(pageCount(n, page));
}

// T: O(1)
// S: O(1) extra space
function pageCount(n: number, page: number): number {
  const fromFront: number = Math.trunc(page / 2);
  const fromBack: number = Math.trunc(n / 2) - fromFront;
  return Math.min(fromFront, fromBack);
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
