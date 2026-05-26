// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

function main() {
  const n: number = +readLine();
  staircase(n);
}

// T: O(n^2)
// S: O(n) extra space
function staircase(n: number) {
  for (let i = 1; i <= n; i++) {
    const spaces = ' '.repeat(n - i);
    const hashes = '#'.repeat(i);
    console.log(spaces + hashes);
  }
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
