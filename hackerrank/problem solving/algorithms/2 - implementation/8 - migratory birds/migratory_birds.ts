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
  const birdCounts: Map<number, number> = countNumbersIntoMap();
  console.log(findMostSpottedBird(birdCounts));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function countNumbersIntoMap(): Map<number, number> {
  const numberCounts = new Map<number, number>();
  readLine()
    .split(' ')
    .forEach((x: any) => {
      x = +x;
      numberCounts.set(x, (numberCounts.get(x) ?? 0) + 1);
    });
  return numberCounts;
}

function findMostSpottedBird(birdCounts: Map<number, number>): number {
  let mostSpottedBird = 0;
  let maxCount = 0;
  for (const [bird, count] of birdCounts.entries()) {
    if (count > maxCount || (count === maxCount && bird < mostSpottedBird)) {
      mostSpottedBird = bird;
      maxCount = count;
    }
  }
  return mostSpottedBird;
}
