// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

function main() {
  const [price, discount, minPrice, budget] = readNumbers();
  console.log(howManyGamesCanBeBought(price, discount, minPrice, budget));
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
}

// T: O(budget / minPrice)
// S: O(1) extra space
function howManyGamesCanBeBought(price, discount, minPrice, budget) {
  let count = 0;
  while (budget >= price) {
    count++;
    budget -= price;
    price = Math.max(price - discount, minPrice);
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
