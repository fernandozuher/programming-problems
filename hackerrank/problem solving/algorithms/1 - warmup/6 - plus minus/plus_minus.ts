// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

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
  const numbers: number[] = readNumbers();
  const ratios: number[] = plusMinus(numbers);
  printRatios(ratios);
}

function readLine(): string {
  return inputLines[currentLine++];
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function plusMinus(numbers: number[]): number[] {
  let [positive, negative, zero] = [0, 0, 0];

  for (const x of numbers)
    if (x > 0) ++positive;
    else if (x < 0) ++negative;
    else ++zero;

  const n: number = numbers.length;
  return [positive / n, negative / n, zero / n];
}

function printRatios(ratios: number[]): void {
  for (const ratio of ratios) console.log(ratio.toFixed(6));
}
