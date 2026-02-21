// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

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

function readLine(): string {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  const [, k]: number[] = readNumbers();
  const numbers: number[] = readNumbers();
  console.log(divisibleSumPairs(numbers, k));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

// n: length of array numbers
// k: length of array frequency
// T: O(n + k)
// S: O(k) extra space
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
  for (let i = 1, n = Math.trunc((frequency.length + 1) / 2); i < n; i++)
    count += frequency[i] * frequency.at(-i);
  return count;
}

function countPairsWithRemainderKHalf(frequency: number[]): number {
  const n: number = frequency.length;
  return n % 2 === 0 ? pairCount(frequency[n / 2]) : 0;
}
