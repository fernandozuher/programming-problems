// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

import { read, skipInputLn } from 'morfo';

function main() {
  skipInputLn();
  const steps: string = read(String);
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

main();
