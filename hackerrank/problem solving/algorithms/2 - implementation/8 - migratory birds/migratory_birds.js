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
  const birdCounts = countNumbersIntoMap();
  console.log(findMostSpottedBird(birdCounts));
}

function readLine() {
  return inputLines[currentLine++];
}

function countNumbersIntoMap() {
  const numberCounts = new Map();
  readLine()
    .split(' ')
    .forEach((x) => {
      x = +x;
      numberCounts.set(x, (numberCounts.get(x) ?? 0) + 1);
    });
  return numberCounts;
}

function findMostSpottedBird(birdCounts) {
  let mostSpottedBird = 0;
  let maxCount = 0;
  for (const [bird, count] of birdCounts.entries()) {
    if (count > maxCount || (count === maxCount && bird < mostSpottedBird)) {
      mostSpottedBird = bird;
      maxCount = count;
    }
  }
  return mostSpottedBird;
}
