// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

function main() {
  const n = +readLine();
  for (let i = 0; i < n; i++) {
    const [a, b]: number[] = readNumbers();
    console.log(squares(a, b));
  }
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// T: O(1)
// S: O(1) extra space
function squares(startNum: number, endNum: number): number {
  const minSquare: number = Math.ceil(Math.sqrt(startNum));
  const maxSquare: number = Math.floor(Math.sqrt(endNum));
  return maxSquare - minSquare + 1;
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
