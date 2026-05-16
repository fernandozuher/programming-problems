// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

function main() {
  const [, k]: number[] = readNumbers();
  const numbers: number[] = readNumbers();
  console.log(divisibleSumPairs(numbers, k));
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of numbers
// k: length of freq
// T: O(n + k)
// S: O(k) extra space
function divisibleSumPairs(numbers: number[], k: number): number {
  const freq: number[] = initRemainderFrequency(numbers, k);
  return (
    countPairsWithRemainder0(freq) +
    countComplementaryRemainderPairs(freq) +
    countPairsWithRemainderKHalf(freq)
  );
}

function initRemainderFrequency(numbers: number[], k: number): number[] {
  const freq = new Array(k).fill(0);
  for (const x of numbers) freq[x % k]++;
  return freq;
}

function countPairsWithRemainder0(freq: number[]): number {
  return pairCount(freq[0]);
}

function pairCount(n: number): number {
  return (n * (n - 1)) / 2;
}

function countComplementaryRemainderPairs(freq: number[]): number {
  let count = 0;
  for (let i = 1, n = Math.trunc((freq.length + 1) / 2); i < n; i++)
    count += freq[i] * freq.at(-i);
  return count;
}

function countPairsWithRemainderKHalf(freq: number[]): number {
  const n: number = freq.length;
  return n % 2 === 0 ? pairCount(freq[n / 2]) : 0;
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
