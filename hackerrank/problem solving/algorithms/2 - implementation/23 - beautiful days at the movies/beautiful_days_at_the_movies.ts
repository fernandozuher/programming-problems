// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

function main() {
  const [startDay, endDay, divisor]: number[] = readNumbers();
  console.log(beautifulDays(startDay, endDay, divisor));
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

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

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
