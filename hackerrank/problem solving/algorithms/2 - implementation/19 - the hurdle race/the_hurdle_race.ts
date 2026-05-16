// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

function main() {
  const maxJump: number = readNumbers()[1];
  const hurdles: number[] = readNumbers();
  console.log(hurdleRace(hurdles, maxJump));
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of hurdles
// T: O(n)
// S: O(1) extra space
function hurdleRace(hurdles: number[], maxJump: number): number {
  return Math.max(0, Math.max(...hurdles) - maxJump);
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
