// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

function main() {
  const [_, jumpLength] = readNumbers();
  const arr = readNumbers();
  console.log(jumpingOnTheClouds(arr, jumpLength));
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of clouds; 2 to 25
// k (jumpLength): 1 <= k <= n
// n % k = 0
// c[i] = 0 or 1
// T: O(n) = O(25) = O(1)
// S: O(1) extra space
function jumpingOnTheClouds(clouds, jumpLength) {
  let energy = 100;

  for (let cloudIndex = 0; ; ) {
    energy -= clouds[cloudIndex] === 0 ? 1 : 3;
    cloudIndex = (cloudIndex + jumpLength) % clouds.length;
    if (!cloudIndex) break;
  }

  return energy;
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
