// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

import { readLn } from 'morfo';

function main() {
  const tripletA: number[] = readLn(Number);
  const tripletB: number[] = readLn(Number);
  const [scoreA, scoreB]: number[] = computeTripletScores(tripletA, tripletB);
  console.log(scoreA, scoreB);
}

// n: length of a and b = 3
// T: O(3) => O(1)
// S: O(1) extra space
function computeTripletScores(tripletA: number[], tripletB: number[]): number[] {
  let [scoreA, scoreB]: number[] = [0, 0];

  for (let i = 0; i < tripletA.length; i++)
    if (tripletA[i] > tripletB[i]) scoreA++;
    else if (tripletB[i] > tripletA[i]) scoreB++;

  return [scoreA, scoreB];
}

main();
