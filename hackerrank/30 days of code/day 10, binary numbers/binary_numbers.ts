// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

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

function readLine(): string {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  let n: number = +readLine();
  let binary = n.toString(2);
  console.log(findMaxLengthOfOnes(binary));
}

function findMaxLengthOfOnes(binary: string): number {
  return Math.max(...binary.split('0').map(segment => segment.length));
}
