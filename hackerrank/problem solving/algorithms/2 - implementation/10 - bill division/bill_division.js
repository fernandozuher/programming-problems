// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

function main() {
  const data = readInput();
  console.log(bonAppetit(data) || 'Bon Appetit');
}

function readInput() {
  const [, itemNotEaten] = readNumbers();
  const mealCosts = readNumbers();
  const amountCharged = +readLine();
  return { itemNotEaten, mealCosts, amountCharged };
}

function readNumbers() {
  return readLine()
    .split(' ')
    .map((x) => +x);
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

////////////////////////////////////////////////

const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin });
let inputLines = [];
rl.on('line', (line) => inputLines.push(line));
rl.on('close', main);

function readLine() {
  return inputLines.shift();
}
