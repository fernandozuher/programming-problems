// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

function main() {
  const n: number = +readLine();
  for (let i = 0; i < n; i++) {
    const [prisoners, sweets, startChair] = readNumbers();
    console.log(saveThePrisoner(prisoners, sweets, startChair));
  }
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// T: O(1)
// S: O(1) extra space
function saveThePrisoner(
  prisoners: number,
  sweets: number,
  startChair: number,
): number {
  return ((startChair - 1 + sweets - 1) % prisoners) + 1;
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
