// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

function main() {
  readLine();
  const chocolateSquares = readNumbers();
  const dayMonth = readNumbers();
  console.log(birthday(chocolateSquares, dayMonth));
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// n: length of chocolateSquares
// 1 <= n <= 100
// T: O(n) = O(100) = O(1)
// S: O(1) extra space
function birthday(chocolateSquares, dayMonth) {
  const [day, month] = dayMonth;
  if (month > chocolateSquares.length) return 0;

  let sum = 0;
  for (let i = 0; i < month; i++) sum += chocolateSquares[i];
  let count = Number(sum === day);

  for (let i = month; i < chocolateSquares.length; i++) {
    sum += chocolateSquares[i] - chocolateSquares[i - month];
    if (sum === day) count++;
  }

  return count;
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
