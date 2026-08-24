// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

import { counter, readLn, skipInputLn } from 'morfo';

const birdsToCounts: Map<number, number> = readInput();
console.log(findMostSpottedBird(birdsToCounts));

// n: length of input
// T: O(n)
// S: O(n) extra space
function readInput(): Map<number, number> {
  skipInputLn();
  return counter(readLn(Number));
}

// n: length of birdsToCounts
// T: O(n)
// S: O(1) extra space
function findMostSpottedBird(birdsToCounts: Map<number, number>): number {
  let resID = 0,
    resCount = 0;

  for (const [id, count] of birdsToCounts)
    if (count > resCount || (count === resCount && id < resID)) {
      resID = id;
      resCount = count;
    }

  return resID;
}
