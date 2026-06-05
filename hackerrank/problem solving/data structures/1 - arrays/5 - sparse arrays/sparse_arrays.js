// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

function main() {
  let n = +readLine();
  const strings = readLines(n);
  const stringsToCounts = counter(strings);

  n = +readLine();
  const queries = readLines(n);

  countsFrom(stringsToCounts, queries).forEach((x) => console.log(x));
}

function readLines(n) {
  return Array.from({ length: n }, readLine);
}

function counter(arr) {
  const freqMap = new Map();
  for (const x of arr) freqMap.set(x, (freqMap.get(x) || 0) + 1);
  return freqMap;
}

// n: length of queries
// maxQueryStringLength: 20
// T: O(n * maxQueryStringLength) = O(n * 20) = O(n)
// S: O(n) extra space
function countsFrom(freqMap, queries) {
  return queries.map((q) => freqMap.get(q) || 0);
}

//////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
const inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
