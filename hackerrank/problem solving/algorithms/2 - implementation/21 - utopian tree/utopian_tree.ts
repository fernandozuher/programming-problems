// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

function main() {
  const n: number = +readLine();
  const utopianTree: number[] = generateHeightsUtopianTree();
  for (let i = 0; i < n; i++) {
    const cycles: number = +readLine();
    console.log(utopianTree[cycles]);
  }
}

// k: length of output = 61
// T: O(k) = O(61) = O(1)
// S: O(61) = O(1) extra space
function generateHeightsUtopianTree(): number[] {
  const maxCycles = 60;
  const heights = new Array<number>(maxCycles + 1);

  for (let cycle = 0, n = maxCycles + 1, height = 0; cycle < n; cycle++) {
    height += isCycleHappeningDuringSpring(cycle) ? height : 1;
    heights[cycle] = height;
  }

  return heights;
}

function isCycleHappeningDuringSpring(cycle: number): boolean {
  return (cycle & 1) === 1;
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
