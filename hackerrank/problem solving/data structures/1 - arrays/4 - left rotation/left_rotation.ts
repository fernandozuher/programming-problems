// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

function main() {
  const [_, rotateBy]: number[] = readNumbers();
  const arr: number[] = readNumbers();
  rotate(arr, rotateBy);
  arr.forEach((x) => process.stdout.write(`${x} `));
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of arr
// rotateBy <= n
// T: O(n)
// S: O(rotateBy) extra space
function rotate(arr: number[], rotateBy: number) {
  if (rotateBy >= arr.length) rotateBy %= arr.length;
  arr.push(...arr.splice(0, rotateBy));
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
