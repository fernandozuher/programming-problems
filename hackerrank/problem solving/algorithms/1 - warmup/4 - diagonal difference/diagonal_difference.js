// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

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
  const n = +readLine();
  console.log(diagonalDifference(n));
}

function readLine() {
  return inputLines[currentLine++];
}

function diagonalDifference(n) {
  let [primarySum, secondarySum] = [0, 0];

  for (let i = 0; i < n; i++) {
    const numbers = readNumbers();
    primarySum += numbers[i];
    secondarySum += numbers[n - i - 1];
  }

  return Math.abs(primarySum - secondarySum);
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}
