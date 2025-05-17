// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

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
  const numbers = readArray();
  console.log(sum(numbers));
}

function readLine() {
  return inputLines[currentLine++];
}

function readArray() {
  return readLine().split(' ').map(Number);
}

function sum(array) {
  return array.reduce((a, b) => a + b, 0);
}
