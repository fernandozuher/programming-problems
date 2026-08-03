// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

function main() {
  const [price, discount, minPrice, budget] = readNums();
  console.log(howManyGamesCanBeBought(price, discount, minPrice, budget));
}

function readNums() {
  return readLine().split(' ').map(Number);
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
const inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
