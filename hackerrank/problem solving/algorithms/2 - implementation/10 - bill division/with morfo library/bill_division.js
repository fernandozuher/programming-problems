// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

import { read, sum, orIfFalsy } from 'morfo';

const data = readInput();
console.log(orIfFalsy(bonAppetit(data), 'Bon Appetit'));

function readInput() {
  const n = read(Number);
  const itemNotEaten = read(Number);
  const mealCosts = read(n, Number);
  const amountCharged = read(Number);
  return { itemNotEaten, mealCosts, amountCharged };
}

// n: length of data.mealCosts
// T: O(n)
// S: O(1) extra space
function bonAppetit(data) {
  const totalCost = sum(data.mealCosts);
  let totalSharedCost = totalCost - data.mealCosts[data.itemNotEaten];
  totalSharedCost /= 2;
  return data.amountCharged - totalSharedCost;
}
