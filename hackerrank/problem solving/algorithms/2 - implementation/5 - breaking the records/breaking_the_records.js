// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

function main() {
  readLine();
  const [mostRecordBreaks, leastRecordBreaks] = breakingRecords(readNumbers());
  console.log(`${mostRecordBreaks} ${leastRecordBreaks}`);
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
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

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
