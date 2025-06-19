// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

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
  const [, k]: number[] = readNumbers();
  const numbers: number[] = readNumbers();
  console.log(divisibleSumPairs(numbers, k));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function readLine(): string {
  return inputLines[currentLine++];
}

function divisibleSumPairs(numbers: number[], k: number): number {
  const frequency: number[] = initRemainderFrequency(numbers, k);
  return (
    countPairsWithRemainder0(frequency) +
    countComplementaryRemainderPairs(frequency) +
    countPairsWithRemainderKHalf(frequency)
  );
}

function initRemainderFrequency(numbers: number[], k: number): number[] {
  const frequency = new Array(k).fill(0);
  for (const x of numbers) frequency[x % k]++;
  return frequency;
}

function countPairsWithRemainder0(frequency: number[]): number {
  return pairCount(frequency[0]);
}

function pairCount(n: number): number {
  return (n * (n - 1)) / 2;
}

function countComplementaryRemainderPairs(frequency: number[]): number {
  let count = 0;
  const k: number = frequency.length;
  for (let i = 1, n = Math.trunc((k + 1) / 2); i < n; i++)
    count += frequency[i] * frequency[k - i];
  return count;
}

function countPairsWithRemainderKHalf(frequency: number[]): number {
  const k: number = frequency.length;
  return k % 2 === 0 ? pairCount(frequency[k / 2]) : 0;
}
