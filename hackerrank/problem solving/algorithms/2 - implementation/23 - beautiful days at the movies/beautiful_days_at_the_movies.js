// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

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

function main() {
  const [startDay, endDay, divisor] = readNumbers();
  console.log(beautifulDays(startDay, endDay, divisor));
}

function readLine() {
  return inputLines[currentLine++];
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function beautifulDays(startDay, endDay, divisor) {
  let count = 0;
  for (let day = startDay; day <= endDay; day++)
    count += isDayBeautiful(day, divisor);
  return count;
}

function isDayBeautiful(day, divisor) {
  return Math.abs(day - reverseNumber(day)) % divisor === 0;
}

function reverseNumber(number) {
  return +String(number).split('').reverse().join('');
}
