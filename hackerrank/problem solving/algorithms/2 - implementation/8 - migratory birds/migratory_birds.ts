// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

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
  const birds: number[] = readNumbers();
  console.log(findMostSpottedBird(birds));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function findMostSpottedBird(birds: number[]): number {
  const birdCount: { [key: number]: number } = {};
  for (const bird of birds) {
    birdCount[bird] = (birdCount[bird] || 0) + 1;
  }

  let mostSpottedBird = 0;
  let maxCount = 0;
  for (const [bird, count] of Object.entries(birdCount)) {
    if (count > maxCount || (count === maxCount && +bird < mostSpottedBird)) {
      mostSpottedBird = +bird;
      maxCount = count;
    }
  }

  return mostSpottedBird;
}
