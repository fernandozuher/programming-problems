// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

function main() {
  const n = +readLine();
  console.log(factorial(n).toString());
}

// T: O(n)
// S: O(1) extra space (excluding the size of the resulting integer)
function factorial(n) {
  let res = BigInt(1);
  for (let i = BigInt(1); i <= n; i++) res *= i;
  return res;
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
