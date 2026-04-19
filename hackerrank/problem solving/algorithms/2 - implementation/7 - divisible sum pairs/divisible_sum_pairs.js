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
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of numbers
// k: length of freq
// T: O(n + k)
// S: O(k) extra space
function divisibleSumPairs(numbers, k) {
  const freq = initRemainderFrequency(numbers, k);
  return (
    countPairsWithRemainder0(freq) +
    countComplementaryRemainderPairs(freq) +
    countPairsWithRemainderKHalf(freq)
  );
}

function initRemainderFrequency(numbers, k) {
  const freq = new Array(k).fill(0);
  for (const x of numbers) freq[x % k]++;
  return freq;
}

function countPairsWithRemainder0(freq) {
  return pairCount(freq[0]);
}

function pairCount(n) {
  return (n * (n - 1)) / 2;
}

function countComplementaryRemainderPairs(freq) {
  let count = 0;
  for (let i = 1, n = Math.trunc((freq.length + 1) / 2); i < n; i++)
    count += freq[i] * freq.at(-i);
  return count;
}

function countPairsWithRemainderKHalf(freq) {
  const n = freq.length;
  return n % 2 === 0 ? pairCount(freq[n / 2]) : 0;
}
