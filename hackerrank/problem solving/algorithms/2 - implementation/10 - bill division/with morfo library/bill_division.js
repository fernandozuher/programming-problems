// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

import { read } from 'morfo';

const data = readInput();
console.log(bonAppetit(data) || 'Bon Appetit');

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
  const totalCost = data.mealCosts.reduce((a, b) => a + b, 0);
  let totalSharedCost = totalCost - data.mealCosts[data.itemNotEaten];
  totalSharedCost /= 2;
  return data.amountCharged - totalSharedCost;
}
