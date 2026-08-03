// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

function main() {
  const [_, t]: number[] = readNums();
  const widths = readNums();
  for (let i = 0; i < t; i++)
    console.log(minWidthInSegment(widths, readNums()));
}

function readNums(): number[] {
  return readLine().split(' ').map(Number);
}

// n: length of widths
// T: O(n)
// S: O(1) extra space
function minWidthInSegment(widths: number[], segment: number[]): number {
  const [start, finish]: number[] = segment;
  let minEl: number = widths[start];
  for (let i = start; i <= finish; ++i) minEl = Math.min(minEl, widths[i]);
  return minEl;
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
