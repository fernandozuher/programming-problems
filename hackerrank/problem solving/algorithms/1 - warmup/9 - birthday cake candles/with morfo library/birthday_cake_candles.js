// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

import { skipInputLn, readLn } from 'morfo';

skipInputLn();
const candles = readLn(Number);
console.log(birthdayCakeCandles(candles));

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
