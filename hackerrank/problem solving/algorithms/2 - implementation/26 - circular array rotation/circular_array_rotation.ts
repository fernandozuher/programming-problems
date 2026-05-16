// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

function main() {
  const [_, nRotation, nQueries]: number[] = readNumbers();
  const arr: number[] = readNumbers();
  for (const q of queries(arr, nRotation, nQueries)) console.log(q);
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// T: O(nQueries)
// S: O(1) extra space
function* queries(
  arr: number[],
  nRotation: number,
  nQueries: number,
): Generator<number | undefined> {
  const offset: number = nRotation % arr.length;
  for (let i = 0; i < nQueries; i++) {
    const query = +readLine();
    yield arr.at(query - offset);
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
