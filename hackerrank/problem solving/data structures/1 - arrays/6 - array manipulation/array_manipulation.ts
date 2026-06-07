// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

function main() {
  const [n, nQueries]: number[] = readNumbers();
  console.log(arrayManipulation(n, nQueries));
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// T: O(n + nQueries)
// S: O(n) extra space
function arrayManipulation(n: number, nQueries: number): number {
  const arr: number[] = populateArr(n, nQueries);
  return maxSequentialSum(arr);
}

function populateArr(n: number, nQueries: number): number[] {
  // +2 = 1-indexed array + range-end
  const arr: number[] = new Array(n + 2).fill(0);

  for (let i = 0; i < nQueries; i++) {
    const [b, e, summand]: number[] = readNumbers();
    arr[b] += summand;
    arr[e + 1] -= summand;
  }

  return arr;
}

function maxSequentialSum(arr: number[]): number {
  let sum: number = 0;
  let max: number = 0;

  for (const x of arr) {
    sum += x;
    max = Math.max(max, sum);
  }

  return max;
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
