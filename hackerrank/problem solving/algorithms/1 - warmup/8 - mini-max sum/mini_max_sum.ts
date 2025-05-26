// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function (inputStdin: string): void {
  inputString += inputStdin;
});

process.stdin.on('end', function (): void {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

//////////////////////////////////////////////////

function main() {
  const numbers: number[] = readNumbers();
  const [minSum, maxSum] = calcMinMaxSum(numbers);
  console.log(`${minSum} ${maxSum}`);
}

function readLine(): string {
  return inputLines[currentLine++];
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function calcMinMaxSum(numbers: number[]): number[] {
  let sum, min, max: number;
  sum = min = max = numbers[0];

  for (let i = 1; i < numbers.length; i++) {
    sum += numbers[i];
    min = Math.min(min, numbers[i]);
    max = Math.max(max, numbers[i]);
  }

  return [sum - max, sum - min];
}
