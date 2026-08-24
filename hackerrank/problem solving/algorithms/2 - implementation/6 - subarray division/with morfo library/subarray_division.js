// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

import { readLn, skipInputLn, sum } from 'morfo';

skipInputLn();
const chocolateSquares = readLn(Number);
const dayMonth = readLn(Number);
console.log(birthday(chocolateSquares, dayMonth));

// n: length of chocolateSquares
// 1 <= n <= 100
// T: O(n) = O(100) = O(1)
// S: O(1) extra space
function birthday(chocolateSquares, dayMonth) {
  const [day, month] = dayMonth;
  if (month > chocolateSquares.length) return 0;

  let windowSum = sum(chocolateSquares.slice(0, month));
  let count = Number(windowSum === day);

  for (let i = month; i < chocolateSquares.length; i++) {
    windowSum += chocolateSquares[i] - chocolateSquares[i - month];
    if (windowSum === day) count++;
  }

  return count;
}
