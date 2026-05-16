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
  const [, itemNotEaten]: number[] = readNumbers();
  const mealCosts: number[] = readNumbers();
  const amountCharged: number = +readLine();
  return { itemNotEaten, mealCosts, amountCharged };
}

function readNumbers(): number[] {
  return readLine()
    .split(' ')
    .map((x) => +x);
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
let inputLines: string[] = [];
rl.on('line', (line: string) => inputLines.push(line));
rl.on('close', main);

function readLine(): string {
  return inputLines.shift()!;
}
