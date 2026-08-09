// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

import { read } from 'morfo';

const startDay = read(Number);
const endDay = read(Number);
const divisor = read(Number);
console.log(beautifulDays(startDay, endDay, divisor));

// n: range (endDay - startDay + 1)
// d: number of digits of the largest day
// T: O(n * d)
// S: O(d) extra space
function beautifulDays(startDay, endDay, divisor) {
  let count = 0;
  for (let day = startDay; day <= endDay; day++)
    if (isBeautifulDay(day, divisor)) count++;
  return count;
}

function isBeautifulDay(day, divisor) {
  return (day - reverseNumber(day)) % divisor === 0;
}

function reverseNumber(number) {
  return +String(number).split('').reverse().join('');
}
