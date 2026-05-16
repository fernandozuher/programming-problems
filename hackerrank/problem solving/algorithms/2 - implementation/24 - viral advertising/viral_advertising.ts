// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

function main() {
  const days: number = +readLine();
  console.log(viralAdvertising(days));
}

// n: days
// T: O(n)
// S: O(1) extra space
function viralAdvertising(days: number): number {
  let acc = 0;
  for (let shared = 5; days > 0; days--) {
    const liked = Math.trunc(shared / 2);
    shared = liked * 3;
    acc += liked;
  }
  return acc;
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
