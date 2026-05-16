// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

const TRANSITION_YEAR = 1918;

function main() {
  const year = +readLine();
  console.log(calcDateOf256thDay(year));
}

// T: O(1)
// S: O(1) extra space
function calcDateOf256thDay(year) {
  let day;
  if (year === TRANSITION_YEAR) day = 26;
  else day = isLeapYear(year) ? 12 : 13;
  return day + '.09.' + year;
}

function isLeapYear(year) {
  if (year < TRANSITION_YEAR) return isLeapJulianYear(year);
  if (year > TRANSITION_YEAR) return isLeapGregorianYear(year);
  return false;
}

function isLeapJulianYear(year) {
  return year % 4 === 0;
}

function isLeapGregorianYear(year) {
  return year % 400 === 0 || (year % 4 === 0 && year % 100 !== 0);
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
