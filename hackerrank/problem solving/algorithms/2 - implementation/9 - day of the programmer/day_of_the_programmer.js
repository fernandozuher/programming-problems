// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

//////////////////////////////////////////////////

const TRANSITION_YEAR = 1918;

function main() {
  let year = +readLine();
  console.log(calculateDateOf256thDay(year));
}

function readLine() {
  return inputLines[currentLine++];
}

function calculateDateOf256thDay(year) {
  let day;
  if (year === TRANSITION_YEAR) day = '26';
  else day = isLeapYear(year) ? '12' : '13';
  return day + '.09.' + year.toString();
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
