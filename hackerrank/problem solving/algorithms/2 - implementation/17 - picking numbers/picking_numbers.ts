// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

function main() {
  readLine();
  const freqMap: Map<number, number> = counter(readNumbers());
  console.log(pickingNumbers(freqMap));
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of arr
// k: length of freqMap
// k <= n
// T: O(n)
// S: O(k) extra space
function counter(arr: number[]): Map<number, number> {
  const freqMap = new Map<number, number>();
  for (const num of arr) {
    freqMap.set(num, (freqMap.get(num) || 0) + 1);
  }
  return freqMap;
}

// k: length of freqMap
// 1 <= k <= 99
// T: O(k) = O(99) = O(1)
// S: O(1) extra space
function pickingNumbers(freqMap: Map<number, number>): number {
  let maxLen = 0;
  for (const [num, _] of freqMap) {
    const current: number = freqMap.get(num) + (freqMap.get(num + 1) || 0);
    maxLen = Math.max(maxLen, current);
  }
  return maxLen;
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
