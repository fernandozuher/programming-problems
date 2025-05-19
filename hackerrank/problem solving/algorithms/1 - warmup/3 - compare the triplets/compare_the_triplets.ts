// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

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
  const tripletA: number[] = readInput();
  const tripletB: number[] = readInput();
  const [scoreA, scoreB]: number[] = compareTriplets(tripletA, tripletB);
  console.log(scoreA, scoreB);
}

function readLine(): string {
  return inputLines[currentLine++];
}

function readInput(): number[] {
  return readLine().split(' ').map(Number);
}

function compareTriplets(tripletA: number[], tripletB: number[]): number[] {
  let [scoreA, scoreB]: number[] = [0, 0];

  for (let i = 0; i < tripletA.length; i++)
    if (tripletA[i] > tripletB[i]) ++scoreA;
    else if (tripletB[i] > tripletA[i]) ++scoreB;

  return [scoreA, scoreB];
}
