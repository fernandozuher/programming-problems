// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

function main() {
  let validRange = false;

  for (
    let lower = +readLine(), num = lower, upper = +readLine();
    num <= upper;
    num++
  )
    if (isNumberKaprekar(num)) {
      process.stdout.write(num + ' ');
      validRange = true;
    }

  if (!validRange) console.log('INVALID RANGE');
}

// log n: for calculating number of digits
// T: O(log n)
// S: O(1) extra space
function isNumberKaprekar(n) {
  const squareNumber = Math.pow(n, 2);
  const divisor = Math.pow(10, numberDigits(n));
  const leftNumber = Math.trunc(squareNumber / divisor);
  const rightNumber = squareNumber % divisor;
  return n === leftNumber + rightNumber;
}

function numberDigits(n) {
  return Math.trunc(Math.log10(n)) + 1;
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
