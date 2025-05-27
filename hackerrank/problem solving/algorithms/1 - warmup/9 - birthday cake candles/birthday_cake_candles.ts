// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

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
  const candles: number[] = readNumbers();
  console.log(birthdayCakeCandles(candles));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function birthdayCakeCandles(candles: number[]): number {
  const max = Math.max(...candles);
  return candles.filter((x) => x === max).length;
}
