// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

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
  let n1: number = +readLine();
  let n2: number = +readLine();
  console.log(solveMeFirst(n1, n2));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function solveMeFirst(n1: number, n2: number): number {
  return n1 + n2;
}
