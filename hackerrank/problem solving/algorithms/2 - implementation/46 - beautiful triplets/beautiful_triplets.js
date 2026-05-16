// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

function main() {
  const [, beautifulDifference] = readNumbers();
  const arr = readNumbers();
  console.log(findBeautifulTriplets(arr, beautifulDifference));
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of arr
// k: distinct numbers of arr
// k <= n
// T: O(n)
// S: O(k) = O(n) extra space
function findBeautifulTriplets(arr, beautifulDifference) {
  const values = new Set(arr);
  const doubleBD = 2 * beautifulDifference;
  let count = 0;

  for (const x of arr) {
    if (values.has(x + beautifulDifference) && values.has(x + doubleBD))
      count++;
  }

  return count;
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
