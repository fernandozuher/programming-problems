// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

import { idiv, read, readLn } from 'morfo';

for (let i = 0, n = read(Number); i < n; i++) {
  const [money, cost, wrappersNeeded] = readLn(Number);
  console.log(howManyChocolatesCanBeEaten(money, cost, wrappersNeeded));
}

// T: O(log(money / cost))
// S: O(1) extra space
function howManyChocolatesCanBeEaten(money, cost, wrappersNeeded) {
  let chocolates = idiv(money, cost);

  for (let wrappers = chocolates; wrappers >= wrappersNeeded;) {
    const freeChocolates = idiv(wrappers, wrappersNeeded);
    wrappers = (wrappers % wrappersNeeded) + freeChocolates;
    chocolates += freeChocolates;
  }

  return chocolates;
}
