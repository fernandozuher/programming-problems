// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

function main() {
  readLine();
  const socksToCounts = counter(readNumbers());
  console.log(sockMerchant(socksToCounts));
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

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// k: length of entries in socksToCounts
// T: O(k)
// S: O(1) extra space
function sockMerchant(socksToCounts) {
  let pairs = 0;
  for (const x of socksToCounts.values()) pairs += Math.trunc(x / 2);
  return pairs;
}

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
