// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

function main() {
  readLine();
  const steps: string = readLine();
  console.log(countingValleys(steps));
}

// n: length of steps
// T: O(n)
// S: O(1) extra space
function countingValleys(steps: string): number {
  let valleys = 0;
  let currentAltitude = 0;

  for (const step of steps) {
    const wasBelowSeaLevel: boolean = currentAltitude < 0;
    currentAltitude += step === 'D' ? -1 : 1;
    const isInSeaLevelFromValley: boolean =
      wasBelowSeaLevel && currentAltitude === 0;
    if (isInSeaLevelFromValley) valleys++;
  }

  return valleys;
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
