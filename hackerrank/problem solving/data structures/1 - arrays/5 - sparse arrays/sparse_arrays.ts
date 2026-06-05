// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

function main() {
  let n: number = +readLine();
  const strings: string[] = readLines(n);
  const stringsToCounts: Map<string, number> = counter(strings);

  n = +readLine();
  const queries: string[] = readLines(n);

  countsFrom(stringsToCounts, queries).forEach((x) => console.log(x));
}

function readLines(n: number): string[] {
  return Array.from({ length: n }, readLine);
}

function counter(arr: string[]): Map<string, number> {
  const freqMap = new Map<string, number>();
  for (const x of arr) freqMap.set(x, (freqMap.get(x) || 0) + 1);
  return freqMap;
}

// n: length of queries
// maxQueryStringLength: 20
// T: O(n * maxQueryStringLength) = O(n * 20) = O(n)
// S: O(n) extra space
function countsFrom(freqMap: Map<string, number>, queries: string[]): number[] {
  return queries.map((q) => freqMap.get(q) || 0);
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
