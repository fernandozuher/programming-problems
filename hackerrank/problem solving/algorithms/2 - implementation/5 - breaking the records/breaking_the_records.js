// https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

function readLine() {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  readLine();
  const scores = readNumbers();
  const [mostRecordBreaks, leastRecordBreaks] = breakingRecords(scores);
  console.log(`${mostRecordBreaks} ${leastRecordBreaks}`);
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

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
