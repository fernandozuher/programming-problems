// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

function main() {
  readLine();
  const socksToCounts = counter(readNums());
  console.log(sockMerchant(socksToCounts));
}

function readNums() {
  return readLine().split(' ').map(Number);
}

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(k) extra space
function counter(arr) {
  const freqMap = new Map();
  for (const x of arr) freqMap.set(x, (freqMap.get(x) || 0) + 1);
  return freqMap;
}

// k: length of entries in socksToCounts
// T: O(k)
// S: O(1) extra space
function sockMerchant(socksToCounts) {
  return Array.from(socksToCounts.values()).reduce(
    (acc, x) => acc + Math.trunc(x / 2),
    0,
  );
}

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
const inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
