// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

const TRANSITION_YEAR: number = 1918;

function main() {
  const year: number = +readLine();
  console.log(calcDateOf256thDay(year));
}

// T: O(1)
// S: O(1) extra space
function calcDateOf256thDay(year: number): string {
  let day: number;
  if (year === TRANSITION_YEAR) day = 26;
  else day = isLeapYear(year) ? 12 : 13;
  return day + '.09.' + year;
}

function isLeapYear(year: number): boolean {
  if (year < TRANSITION_YEAR) return isLeapJulianYear(year);
  if (year > TRANSITION_YEAR) return isLeapGregorianYear(year);
  return false;
}

function isLeapJulianYear(year: number): boolean {
  return year % 4 === 0;
}

function isLeapGregorianYear(year: number): boolean {
  return year % 400 === 0 || (year % 4 === 0 && year % 100 !== 0);
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
