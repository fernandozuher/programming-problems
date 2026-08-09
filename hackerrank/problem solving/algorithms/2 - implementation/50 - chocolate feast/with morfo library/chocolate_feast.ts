// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

import { read, readLn } from 'morfo';

for (let i = 0, n = read(Number); i < n; i++) {
  const [money, cost, wrappersNeeded] = readLn(Number);
  console.log(howManyChocolatesCanBeEaten(money, cost, wrappersNeeded));
}

// T: O(log(money / cost))
// S: O(1) extra space
function howManyChocolatesCanBeEaten(
  money: number,
  cost: number,
  wrappersNeeded: number,
): number {
  let chocolates: number = Math.trunc(money / cost);

  for (let wrappers = chocolates; wrappers >= wrappersNeeded; ) {
    const freeChocolates = Math.trunc(wrappers / wrappersNeeded);
    wrappers = (wrappers % wrappersNeeded) + freeChocolates;
    chocolates += freeChocolates;
  }

  return chocolates;
}
