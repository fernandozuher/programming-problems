// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

function main() {
  readLine();
  const candles: number[] = readNumbers();
  console.log(birthdayCakeCandles(candles));
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of candles
// T: O(n)
// S: O(1) extra space
function birthdayCakeCandles(candles: number[]): number {
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

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
