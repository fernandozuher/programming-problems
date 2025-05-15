// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

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
  let n1 = +readLine();
  let n2 = +readLine();
  console.log(solveMeFirst(n1, n2));
}

function readLine() {
  return inputLines[currentLine++];
}

function solveMeFirst(n1, n2) {
  return n1 + n2;
}
