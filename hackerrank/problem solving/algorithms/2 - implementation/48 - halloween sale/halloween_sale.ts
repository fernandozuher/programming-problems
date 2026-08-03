// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

function main() {
  const [price, discount, minPrice, budget]: number[] = readNums();
  console.log(howManyGamesCanBeBought(price, discount, minPrice, budget));
}

function readNums(): number[] {
  return readLine().split(' ').map(Number);
}

// T: O(budget / minPrice)
// S: O(1) extra space
function howManyGamesCanBeBought(
  price: number,
  discount: number,
  minPrice: number,
  budget: number,
): number {
  let count = 0;
  while (budget >= price) {
    count++;
    budget -= price;
    price = Math.max(price - discount, minPrice);
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
