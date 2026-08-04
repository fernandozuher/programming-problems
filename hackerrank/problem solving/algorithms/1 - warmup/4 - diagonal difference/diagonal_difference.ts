// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

function main() {
  const n: number = +readLine();
  console.log(diagonalDifference(n));
}

// T: O(n^2)
// S: O(n) extra space
function diagonalDifference(n: number): number {
  let [primarySum, secondarySum] = [0, 0];

  for (let i = 0; i < n; i++) {
    const arr: number[] = readNums();
    primarySum += arr[i];
    secondarySum += arr.at(-i - 1)!;
  }

  return Math.abs(primarySum - secondarySum);
}

function readNums(): number[] {
  return readLine().split(' ').map(Number);
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
const inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
