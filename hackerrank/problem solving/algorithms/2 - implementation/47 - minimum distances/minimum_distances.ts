// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

function main() {
  readLine();
  const arr: number[] = readNumbers();
  console.log(minDistance(arr));
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of arr
// T: O(n)
// S: O(n) extra space
function minDistance(arr: number[]): number {
  const lastSeen: { [key: number]: number } = {};
  let minDist = -1;

  for (let i = 0; i < arr.length; i++) {
    const x = arr[i];

    if (lastSeen.hasOwnProperty(x)) {
      const dist = i - lastSeen[x];

      if (minDist === -1 || dist < minDist) {
        minDist = dist;
        if (minDist === 1) return 1;
      }
    }

    lastSeen[x] = i;
  }

  return minDist;
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
