// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

import { skipInputLn, readLn } from 'morfo';

skipInputLn();
const [mostRecordBreaks, leastRecordBreaks]: number[] =
  breakingRecords(readLn(Number));
console.log(`${mostRecordBreaks} ${leastRecordBreaks}`);

// n: length of scores
// T: O(n)
// S: O(1) extra space
function breakingRecords(scores: number[]): number[] {
  let mostPoints: number = scores[0];
  let leastPoints: number = scores[0];
  let mostRecordBreaks: number = 0;
  let leastRecordBreaks: number = 0;

  for (const score of scores)
    if (score > mostPoints) {
      mostPoints = score;
      mostRecordBreaks++;
    } else if (score < leastPoints) {
      leastPoints = score;
      leastRecordBreaks++;
    }

  return [mostRecordBreaks, leastRecordBreaks];
}
