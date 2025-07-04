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

//////////////////////////////////////////////////

function main() {
  const data: Input = readInput();
  printOutput(new BillDivision(data).bonAppetit());
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

function readLine(): string {
  return inputLines[currentLine++];
}

class BillDivision {
  private readonly itemNotEaten: number;
  private readonly mealCosts: number[];
  private readonly amountCharged: number;

  constructor(data: Input) {
    this.itemNotEaten = data.itemNotEaten;
    this.mealCosts = data.mealCosts;
    this.amountCharged = data.amountCharged;
  }

  public bonAppetit(): number {
    return this.amountCharged - this.computeActualShare();
  }

  private computeActualShare(): number {
    const totalCost: number = this.mealCosts.reduce((a, b) => a + b, 0);
    const totalSharedCost: number =
      totalCost - this.mealCosts[this.itemNotEaten];
    return totalSharedCost / 2;
  }
}

function printOutput(charged: number) {
  console.log(charged || 'Bon Appetit');
}
