// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let inputLines = [];
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

function readLine() {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  const data = readInput();
  const charged = bonAppetit(data);
  console.log(charged || 'Bon Appetit');
}

function readInput() {
  const [, itemNotEaten] = readNumbers();
  const mealCosts = readNumbers();
  const amountCharged = +readLine();
  return { itemNotEaten, mealCosts, amountCharged };
}

function readNumbers() {
  return readLine().split(' ').map(Number);
}

function bonAppetit(data) {
  const totalCost = data.mealCosts.reduce((a, b) => a + b, 0);
  let totalSharedCost = totalCost - data.mealCosts[data.itemNotEaten];
  totalSharedCost /= 2;
  return data.amountCharged - totalSharedCost;
}
