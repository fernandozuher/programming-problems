// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

function main() {
  readLine();
  const socksToCounts: Map<number, number> = counter(readNums());
  console.log(sockMerchant(socksToCounts));
}

function readNums(): number[] {
  return readLine().split(' ').map(Number);
}

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(k) extra space
function counter(arr: number[]): Map<number, number> {
  const freqMap = new Map<number, number>();
  for (const x of arr) freqMap.set(x, (freqMap.get(x) || 0) + 1);
  return freqMap;
}

// k: length of entries in socksToCounts
// T: O(k)
// S: O(1) extra space
function sockMerchant(socksToCounts: Map<number, number>): number {
  return Array.from(socksToCounts.values()).reduce(
    (acc: number, x: number) => acc + Math.trunc(x / 2),
    0,
  );
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
const inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
