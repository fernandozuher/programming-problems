// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

function main() {
  readLine();
  const arr: number[] = readNumbers();
  for (const x of sequenceEquation(arr)) console.log(x);
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of arr
// T: O(n)
// S: O(n) extra space
function* sequenceEquation(arr: number[]): Generator<number | undefined> {
  const valuesToIndex: number[] = Array(arr.length).fill(0);
  let i = 0;
  for (const val of arr) valuesToIndex[val - 1] = i++;
  for (const val of valuesToIndex) yield valuesToIndex[val] + 1;
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
