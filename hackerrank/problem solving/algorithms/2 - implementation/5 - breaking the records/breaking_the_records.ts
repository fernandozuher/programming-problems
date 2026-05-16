// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

function main() {
  readLine();
  const [mostRecordBreaks, leastRecordBreaks]: number[] =
    breakingRecords(readNumbers());
  console.log(`${mostRecordBreaks} ${leastRecordBreaks}`);
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

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

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
