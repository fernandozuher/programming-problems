// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

function main() {
  const n = +readLine();
  for (let i = 0; i < n; i++) {
    const num = +readLine();
    console.log(findDigits(num));
  }
}

// k: quantity of digits of num = log num
// 0 < num < 10^9
// T: O(k) = O(9) = O(1)
// S: O(k) = O(9) = O(1) extra space
function findDigits(num) {
  return num
    .toString()
    .split('')
    .filter((c) => {
      const d = +c;
      return d !== 0 && num % d === 0;
    }).length;
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
