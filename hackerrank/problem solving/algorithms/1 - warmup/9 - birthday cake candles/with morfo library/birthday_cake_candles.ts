// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

import { count, skipInputLn, readLn } from 'morfo';

skipInputLn();
const candles: number[] = readLn(Number);
console.log(birthdayCakeCandles(candles));

// n: length of candles
// T: O(2n) = O(n)
// S: O(1) extra space
function birthdayCakeCandles(candles: number[]): number {
  return count(candles, Math.max(...candles));
}
