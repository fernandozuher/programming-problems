// https://www.hackerrank.com/challenges/30-more-exceptions/problem?isFullScreen=true

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
  for (let nTests = +readLine(); nTests--; ) {
    let [n, p] = readLine().split(' ').map(Number);
    power(n, p);
  }
}

function power(n: number, p: number): void {
  try {
    console.log(Calculator.power(n, p));
  } catch (e) {
    console.log(e.message);
  }
}

class Calculator {
  public static power(n: number, p: number): number {
    if (n < 0 || p < 0)
      throw new RangeError('n and p should be non-negative');
    return Math.pow(n, p);
  }
}
