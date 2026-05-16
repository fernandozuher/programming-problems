// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

function main() {
  const birdsToCounts: Map<number, number> = readInput();
  console.log(findMostSpottedBird(birdsToCounts));
}

// n: length of input
// T: O(n)
// S: O(n) extra space
function readInput(): Map<number, number> {
  readLine();
  const freqMap = new Map<number, number>();

  readLine()
    .split(' ')
    .forEach((x: any) => {
      x = +x;
      freqMap.set(x, (freqMap.get(x) ?? 0) + 1);
    });

  return freqMap;
}

// n: length of birdsToCounts
// T: O(n)
// S: O(1) extra space
function findMostSpottedBird(birdsToCounts: Map<number, number>): number {
  let resID = 0,
    resCount = 0;

  for (const [id, count] of birdsToCounts)
    if (count > resCount || (count === resCount && id < resID)) {
      resID = id;
      resCount = count;
    }

  return resID;
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
