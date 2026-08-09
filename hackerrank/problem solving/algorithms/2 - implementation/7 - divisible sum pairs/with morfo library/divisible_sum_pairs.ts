// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

import { readLn } from 'morfo';

function main() {
  const [, k]: number[] = readLn(Number);
  const numbers: number[] = readLn(Number);
  console.log(divisibleSumPairs(numbers, k));
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
    count += freq[i] * freq.at(-i)!;
  return count;
}

function countPairsWithRemainderKHalf(freq: number[]): number {
  const n: number = freq.length;
  return n % 2 === 0 ? pairCount(freq[n / 2]) : 0;
}

main();
