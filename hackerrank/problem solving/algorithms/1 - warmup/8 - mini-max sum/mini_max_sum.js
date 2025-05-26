// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

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
  const numbers = readNumbers();
  const [minSum, maxSum] = calcMinMaxSum(numbers);
  console.log(`${minSum} ${maxSum}`);
}

function readLine() {
  return inputLines[currentLine++];
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function calcMinMaxSum(numbers) {
  let sum, min, max;
  sum = min = max = numbers[0];

  for (let i = 1; i < numbers.length; i++) {
    sum += numbers[i];
    min = Math.min(min, numbers[i]);
    max = Math.max(max, numbers[i]);
  }

  return [sum - max, sum - min];
}
