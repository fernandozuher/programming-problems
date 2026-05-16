// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

function main() {
  const n: number = +readLine();
  for (let i = 0; i < n; i++) {
    const num = +readLine();
    console.log(findDigits(num));
  }
}

// k: quantity of digits of num = log num
// 0 < num < 10^9
// T: O(k) = O(9) = O(1)
// S: O(k) = O(9) = O(1) extra space
function findDigits(num: number): number {
  return num
    .toString()
    .split('')
    .filter((c) => {
      const d = +c;
      return d !== 0 && num % d === 0;
    }).length;
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
