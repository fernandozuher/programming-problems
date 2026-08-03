// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

function main() {
  readLine();
  const chocolateSquares: number[] = readNums();
  const dayMonth: number[] = readNums();
  console.log(birthday(chocolateSquares, dayMonth));
}

function readNums(): number[] {
  return readLine().split(' ').map(Number);
}

// n: length of chocolateSquares
// 1 <= n <= 100
// T: O(n) = O(100) = O(1)
// S: O(1) extra space
function birthday(chocolateSquares: number[], dayMonth: number[]): number {
  const [day, month]: number[] = dayMonth;
  if (month > chocolateSquares.length) return 0;

  let sum: number = 0;
  for (let i = 0; i < month; i++) sum += chocolateSquares[i];
  let count: number = Number(sum === day);

  for (let i = month; i < chocolateSquares.length; i++) {
    sum += chocolateSquares[i] - chocolateSquares[i - month];
    if (sum === day) count++;
  }

  return count;
}

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
const inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
