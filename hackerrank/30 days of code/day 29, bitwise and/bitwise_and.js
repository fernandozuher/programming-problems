// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

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
  for (let testCases = +readLine(); testCases--; ) {
    const [n, k] = readLine().split(' ').map(Number);
    console.log(bitwiseAnd(n, k));
  }
}

function readLine() {
  return inputLines[currentLine++];
}

function bitwiseAnd(n, k) {
  if ((k - 1 | k) <= n)
    return k - 1;
  return k - 2;
}
