// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

import { read } from 'morfo';

interface Input {
  itemNotEaten: number;
  mealCosts: number[];
  amountCharged: number;
}

function main() {
  const data: Input = readInput();
  console.log(bonAppetit(data) || 'Bon Appetit');
}

function readInput(): Input {
  const n: number = read(Number);
  const itemNotEaten: number = read(Number);
  const mealCosts: number[] = read(n, Number);
  const amountCharged: number = read(Number);
  return { itemNotEaten, mealCosts, amountCharged };
}

// n: length of data.mealCosts
// T: O(n)
// S: O(1) extra space
function bonAppetit(data: Input): number {
  const totalCost: number = data.mealCosts.reduce((a, b) => a + b, 0);
  let totalSharedCost: number = totalCost - data.mealCosts[data.itemNotEaten];
  totalSharedCost /= 2;
  return data.amountCharged - totalSharedCost;
}

main();
