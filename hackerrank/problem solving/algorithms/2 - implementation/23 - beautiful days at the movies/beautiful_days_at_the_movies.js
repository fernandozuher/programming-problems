// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

function main() {
  const [startDay, endDay, divisor] = readNumbers();
  console.log(beautifulDays(startDay, endDay, divisor));
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

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

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
