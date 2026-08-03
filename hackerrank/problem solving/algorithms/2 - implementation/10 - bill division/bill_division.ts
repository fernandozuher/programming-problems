// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

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
  const [, itemNotEaten]: number[] = readNums();
  const mealCosts: number[] = readNums();
  const amountCharged: number = +readLine();
  return { itemNotEaten, mealCosts, amountCharged };
}

function readNums(): number[] {
  return readLine().split(' ').map(Number);
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

//////////////////////////////////////////////////

import readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
const inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
