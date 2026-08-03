// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true

function main() {
  const [_, rotateBy] = readNums();
  const arr = readNums();
  rotate(arr, rotateBy);
  arr.forEach((x) => process.stdout.write(`${x} `));
}

function readNums() {
  return readLine().split(' ').map(Number);
}

// n: length of arr
// rotateBy <= n
// T: O(n)
// S: O(rotateBy) extra space
function rotate(arr, rotateBy) {
  if (rotateBy >= arr.length) rotateBy %= arr.length;
  arr.push(...arr.splice(0, rotateBy));
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
