// https://www.hackerrank.com/challenges/30-scope/problem?isFullScreen=true

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
  readLine(); // Size not used
  let numbers: number[] = readLine().split(' ').map(Number);
  let difference = new Difference(numbers);
  difference.computeDifference();
  console.log(difference.maximumDifference);
}

class Difference {
  private readonly elements: number[];
  public maximumDifference: number = 0;

  constructor(elements: number[]) {
    this.elements = elements;
  }

  computeDifference() {
    this.maximumDifference = Math.max(...this.elements) - Math.min(...this.elements);
  }
}
