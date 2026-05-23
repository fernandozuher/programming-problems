// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

function main() {
  readLine();
  const arr: number[] = readNumbers();
  console.log(aVeryBigSum(arr));
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
function aVeryBigSum(arr: number[]): number {
  return arr.reduce((a, b) => a + b);
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
