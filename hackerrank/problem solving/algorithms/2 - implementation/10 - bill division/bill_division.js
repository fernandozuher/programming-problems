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

//////////////////////////////////////////////////

function main() {
  const data = readInput();
  printOutput(new BillDivision(data).bonAppetit());
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

function readLine() {
  return inputLines[currentLine++];
}

class BillDivision {
  #itemNotEaten;
  #mealCosts;
  #amountCharged;

  constructor(data) {
    this.#itemNotEaten = data.itemNotEaten;
    this.#mealCosts = data.mealCosts;
    this.#amountCharged = data.amountCharged;
  }

  bonAppetit() {
    return this.#amountCharged - this.#computeActualShare();
  }

  #computeActualShare() {
    const totalCost = this.#mealCosts.reduce((a, b) => a + b, 0);
    const totalSharedCost = totalCost - this.#mealCosts[this.#itemNotEaten];
    return totalSharedCost / 2;
  }
}

function printOutput(charged) {
  console.log(charged || 'Bon Appetit');
}
