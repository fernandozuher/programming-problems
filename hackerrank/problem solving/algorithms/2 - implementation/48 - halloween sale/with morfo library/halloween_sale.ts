// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

import { read } from 'morfo';

const [price, discount, minPrice, budget]: [number, number, number, number] =
  read(Number, Number, Number, Number);
console.log(howManyGamesCanBeBought(price, discount, minPrice, budget));

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
