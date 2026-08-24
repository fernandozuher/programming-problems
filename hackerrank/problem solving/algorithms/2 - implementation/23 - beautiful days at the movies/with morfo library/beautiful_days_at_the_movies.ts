// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

import { read } from 'morfo';

const [startDay, endDay, divisor]: [number, number, number] = read(
  Number,
  Number,
  Number,
);
console.log(beautifulDays(startDay, endDay, divisor));

// n: range (endDay - startDay + 1)
// d: number of digits of the largest day
// T: O(n * d)
// S: O(d) extra space
function beautifulDays(
  startDay: number,
  endDay: number,
  divisor: number,
): number {
  let count = 0;
  for (let day = startDay; day <= endDay; day++)
    if (isBeautifulDay(day, divisor)) count++;
  return count;
}

function isBeautifulDay(day: number, divisor: number): boolean {
  return (day - reverseNumber(day)) % divisor === 0;
}

function reverseNumber(number: number): number {
  return +String(number).split('').reverse().join('');
}
