// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

function readLine() {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  const nTests = +readLine();
  processPrimeTests(nTests);
}

function processPrimeTests(nTests) {
  while (nTests-- > 0) {
    const n = +readLine();
    console.log(isPrime(n) ? 'Prime' : 'Not prime');
  }
}

function isPrime(n) {
  if (n <= 1) return false;
  if (n === 2) return true;
  if (n % 2 === 0) return false;

  for (let divisor = 3, limit = Math.sqrt(n); divisor <= limit; divisor += 2)
    if (n % divisor === 0) return false;
  return true;
}
