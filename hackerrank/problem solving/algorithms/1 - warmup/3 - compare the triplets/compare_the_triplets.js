// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

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
  const tripletA = readInput();
  const tripletB = readInput();
  const [scoreA, scoreB] = compareTriplets(tripletA, tripletB);
  console.log(scoreA, scoreB);
}

function readLine() {
  return inputLines[currentLine++];
}

function readInput() {
  return readLine().split(' ').map(Number);
}

function compareTriplets(tripletA, tripletB) {
  let [scoreA, scoreB] = [0, 0];

  for (let i = 0; i < tripletA.length; i++) {
    if (tripletA[i] > tripletB[i]) ++scoreA;
    else if (tripletB[i] > tripletA[i]) ++scoreB;
  }

  return [scoreA, scoreB];
}
