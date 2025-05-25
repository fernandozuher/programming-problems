// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

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
  const numbers = readNumbers();
  const ratios = plusMinus(numbers);
  printRatios(ratios);
}

function readLine() {
  return inputLines[currentLine++];
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function plusMinus(numbers) {
  let [positive, negative, zero] = [0, 0, 0];

  for (const x of numbers)
    if (x > 0) ++positive;
    else if (x < 0) ++negative;
    else ++zero;

  const n = numbers.length;
  return [positive / n, negative / n, zero / n];
}

function printRatios(ratios) {
  for (const ratio of ratios) console.log(ratio.toFixed(6));
}
