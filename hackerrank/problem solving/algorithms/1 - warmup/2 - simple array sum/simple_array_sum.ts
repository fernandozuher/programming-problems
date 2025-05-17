// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

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
  readLine();
  const numbers: number[] = readArray();
  console.log(sum(numbers));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function readArray(): number[] {
  return readLine().split(' ').map(Number);
}

function sum(array: number[]): number {
  return array.reduce((a, b) => a + b, 0);
}
