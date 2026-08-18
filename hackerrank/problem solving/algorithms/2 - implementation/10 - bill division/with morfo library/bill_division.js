// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

import { read, sum, orIfFalsy } from 'morfo';

const data = readInput();
console.log(orIfFalsy(bonAppetit(data), 'Bon Appetit'));

function readInput() {
  const n = read(Number);
  return {
    itemNotEaten: read(Number),
    mealCosts: read(n, Number),
    amountCharged: read(Number),
  };
}

// n: length of data.mealCosts
// T: O(n)
// S: O(1) extra space
function bonAppetit(data) {
  let totalSharedCost = sum(data.mealCosts) - data.mealCosts[data.itemNotEaten];
  totalSharedCost /= 2;
  return data.amountCharged - totalSharedCost;
}
