// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

function readLine() {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  const [, k] = readNumbers();
  const numbers = readNumbers();
  console.log(divisibleSumPairs(numbers, k));
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

// n: length of array numbers
// k: length of array frequency
// T: O(n + k)
// S: O(k) extra space
function divisibleSumPairs(numbers, k) {
  const frequency = initRemainderFrequency(numbers, k);
  return (
    countPairsWithRemainder0(frequency) +
    countComplementaryRemainderPairs(frequency) +
    countPairsWithRemainderKHalf(frequency)
  );
}

function initRemainderFrequency(numbers, k) {
  const frequency = new Array(k).fill(0);
  for (const x of numbers) frequency[x % k]++;
  return frequency;
}

function countPairsWithRemainder0(frequency) {
  return pairCount(frequency[0]);
}

function pairCount(n) {
  return (n * (n - 1)) / 2;
}

function countComplementaryRemainderPairs(frequency) {
  let count = 0;
  for (let i = 1, n = Math.trunc((frequency.length + 1) / 2); i < n; i++)
    count += frequency[i] * frequency.at(-i);
  return count;
}

function countPairsWithRemainderKHalf(frequency) {
  const n = frequency.length;
  return n % 2 === 0 ? pairCount(frequency[n / 2]) : 0;
}
