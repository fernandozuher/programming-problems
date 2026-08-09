// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

import { read } from 'morfo';

const price = read(Number);
const discount = read(Number);
const minPrice = read(Number);
const budget = read(Number);
console.log(howManyGamesCanBeBought(price, discount, minPrice, budget));

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
