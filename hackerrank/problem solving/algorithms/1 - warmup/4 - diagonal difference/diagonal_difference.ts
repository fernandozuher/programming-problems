// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

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
  const n: number = +readLine();
  console.log(diagonalDifference(n));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function diagonalDifference(n: number): number {
  let [primarySum, secondarySum] = [0, 0];

  for (let i = 0; i < n; ++i) {
    let numbers: number[] = readNumbers();
    primarySum += numbers[i];
    secondarySum += numbers[n - i - 1];
  }

  return Math.abs(primarySum - secondarySum);
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}
