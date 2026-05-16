// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

function main() {
  readLine();
  const steps = readLine();
  console.log(countingValleys(steps));
}

// n: length of steps
// T: O(n)
// S: O(1) extra space
function countingValleys(steps) {
  let valleys = 0;
  let currentAltitude = 0;

  for (const step of steps) {
    const wasBelowSeaLevel = currentAltitude < 0;
    currentAltitude += step === 'D' ? -1 : 1;
    const isInSeaLevelFromValley = wasBelowSeaLevel && currentAltitude === 0;
    if (isInSeaLevelFromValley) valleys++;
  }

  return valleys;
}

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
