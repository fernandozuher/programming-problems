// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

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
  const candles = readNumbers();
  console.log(birthdayCakeCandles(candles));
}

function readLine() {
  return inputLines[currentLine++];
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function birthdayCakeCandles(candles) {
  const max = Math.max(...candles);
  return candles.filter((x) => x === max).length;
}
