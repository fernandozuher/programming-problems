// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

function main() {
  readLine();
  console.log(sumStdin());
}

// n: number of integers in the input line
// T: O(n)
// S: O(n) extra space
function sumStdin() {
  return readLine()
    .split(' ')
    .reduce((acc, x) => acc + +x, 0);
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
