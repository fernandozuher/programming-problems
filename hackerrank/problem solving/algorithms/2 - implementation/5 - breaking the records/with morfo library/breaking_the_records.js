// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

import { skipInputLn, readLn } from 'morfo';

function main() {
  skipInputLn();
  const [mostRecordBreaks, leastRecordBreaks] = breakingRecords(readLn(Number));
  console.log(`${mostRecordBreaks} ${leastRecordBreaks}`);
}

// n: length of scores
// T: O(n)
// S: O(1) extra space
function breakingRecords(scores) {
  let mostPoints = scores[0],
    leastPoints = scores[0];
  let mostRecordBreaks = 0,
    leastRecordBreaks = 0;

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

main();
