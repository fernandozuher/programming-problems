// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

function main() {
  readLine();
  const candles = readNumbers();
  console.log(birthdayCakeCandles(candles));
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of candles
// T: O(n)
// S: O(1) extra space
function birthdayCakeCandles(candles) {
  let max = candles[0];
  let count = 0;

  for (const candle of candles) {
    if (candle > max) {
      max = candle;
      count = 1;
    } else if (candle === max) count++;
  }

  return count;
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
