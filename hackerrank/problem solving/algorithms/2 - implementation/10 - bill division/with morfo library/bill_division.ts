// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

import { read, sum, orIfFalsy } from 'morfo';

interface Input {
  itemNotEaten: number;
  mealCosts: number[];
  amountCharged: number;
}

const data: Input = readInput();
console.log(orIfFalsy(bonAppetit(data), 'Bon Appetit'));

function readInput(): Input {
  const n: number = read(Number);
  return {
    itemNotEaten: read(Number),
    mealCosts: read(n, Number),
    amountCharged: read(Number),
  };
}

// n: length of data.mealCosts
// T: O(n)
// S: O(1) extra space
function bonAppetit(data: Input): number {
  let totalSharedCost: number =
    sum(data.mealCosts) - data.mealCosts[data.itemNotEaten];
  totalSharedCost /= 2;
  return data.amountCharged - totalSharedCost;
}
