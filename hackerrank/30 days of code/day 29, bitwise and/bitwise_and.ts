// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

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
  for (let testCases: number = +readLine(); testCases--; ) {
    const [n, k] = readLine().split(' ').map(Number);
    console.log(bitwiseAnd(n, k));
  }
}

function readLine(): string {
  return inputLines[currentLine++];
}

function bitwiseAnd(n: number, k: number): number {
  if ((k - 1 | k) <= n)
    return k - 1;
  return k - 2;
}
