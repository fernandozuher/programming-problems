// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

import { skipInputLn, readLn } from 'morfo';

skipInputLn();
const chocolateSquares: number[] = readLn(Number);
const dayMonth: number[] = readLn(Number);
console.log(birthday(chocolateSquares, dayMonth));

// n: length of chocolateSquares
// 1 <= n <= 100
// T: O(n) = O(100) = O(1)
// S: O(1) extra space
function birthday(chocolateSquares: number[], dayMonth: number[]): number {
  const [day, month]: number[] = dayMonth;
  if (month > chocolateSquares.length) return 0;

  let sum: number = 0;
  for (let i = 0; i < month; i++) sum += chocolateSquares[i];
  let count: number = Number(sum === day);

  for (let i = month; i < chocolateSquares.length; i++) {
    sum += chocolateSquares[i] - chocolateSquares[i - month];
    if (sum === day) count++;
  }

  return count;
}
