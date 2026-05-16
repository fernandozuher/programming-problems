// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

function main() {
  const n: number = +readLine();
  console.log(factorial(n).toString());
}

// T: O(n)
// S: O(1) extra space (excluding the size of the resulting integer)
function factorial(n: number): BigInt {
  let res = BigInt(1);
  for (let i = BigInt(1); i <= n; i++) res *= i;
  return res;
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
