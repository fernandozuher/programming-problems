// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

'use strict';

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

//////////////////////////////////////////////////

function main() {
  readLine();
  const birds = readNumbers();
  console.log(findMostSpottedBird(birds));
}

function readLine() {
  return inputLines[currentLine++];
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function findMostSpottedBird(birds) {
  const birdCount = {};
  for (const bird of birds) {
    birdCount[bird] = (birdCount[bird] || 0) + 1;
  }

  let mostSpottedBird = 0;
  let maxCount = 0;
  for (const [bird, count] of Object.entries(birdCount)) {
    if (count > maxCount || (count === maxCount && +bird < mostSpottedBird)) {
      mostSpottedBird = +bird;
      maxCount = count;
    }
  }

  return mostSpottedBird;
}
