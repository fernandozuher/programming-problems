// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

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

////////////////////////////////////////////////

function main() {
  readLine();
  const steps = readLine();
  console.log(countingValleys(steps));
}

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
