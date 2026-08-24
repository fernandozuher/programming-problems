// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

import { idiv, read } from 'morfo';

const [lower, upper] = read(Number, Number);
let validRange = false;

for (let num = lower; num <= upper; num++)
  if (isNumberKaprekar(num)) {
    process.stdout.write(num + ' ');
    validRange = true;
  }

if (!validRange) console.log('INVALID RANGE');

// log n: for calculating number of digits
// T: O(log n)
// S: O(1) extra space
function isNumberKaprekar(n) {
  const squareNumber = Math.pow(n, 2);
  const divisor = Math.pow(10, numberDigits(n));
  const leftNumber = idiv(squareNumber, divisor);
  const rightNumber = squareNumber % divisor;
  return n === leftNumber + rightNumber;
}

function numberDigits(n) {
  return Math.trunc(Math.log10(n)) + 1;
}
