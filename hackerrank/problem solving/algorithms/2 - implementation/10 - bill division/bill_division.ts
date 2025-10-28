// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function (inputStdin: string): void {
  inputString += inputStdin;
});

process.stdin.on('end', function (): void {
  inputLines = inputString.split('\n');
  inputString = '';
  main();
});

function readLine(): string {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  const data: Input = readInput();
  const charged: number = bonAppetit(data);
  console.log(charged || 'Bon Appetit');
}

function readInput(): Input {
  const [, itemNotEaten]: number[] = readNumbers();
  const mealCosts: number[] = readNumbers();
  const amountCharged: number = +readLine();
  return { itemNotEaten, mealCosts, amountCharged };
}

interface Input {
  itemNotEaten: number;
  mealCosts: number[];
  amountCharged: number;
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function bonAppetit(data: Input): number {
  const totalCost: number = data.mealCosts.reduce((a, b) => a + b, 0);
  let totalSharedCost: number = totalCost - data.mealCosts[data.itemNotEaten];
  totalSharedCost /= 2;
  return data.amountCharged - totalSharedCost;
}
