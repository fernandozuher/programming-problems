// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

function main() {
  readLine();
  const socksToCounts: Map<number, number> = counter(readNumbers());
  console.log(sockMerchant(socksToCounts));
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

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// k: length of entries in socksToCounts
// T: O(k)
// S: O(1) extra space
function sockMerchant(socksToCounts: Map<number, number>): number {
  let pairs = 0;
  for (const x of socksToCounts.values()) pairs += Math.trunc(x / 2);
  return pairs;
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
