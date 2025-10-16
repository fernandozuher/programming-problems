// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

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
  const n: number = +readLine();
  for (let i = 0; i < n; i++) {
    const [money, cost, wrappersNeeded] = readNumbers();
    console.log(howManyChocolatesCanBeEaten(money, cost, wrappersNeeded));
  }
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function howManyChocolatesCanBeEaten(
  money: number,
  cost: number,
  wrappersNeeded: number,
): number {
  let chocolates: number = Math.trunc(money / cost);

  for (let wrappers = chocolates; wrappers >= wrappersNeeded; ) {
    const freeChocolates = Math.trunc(wrappers / wrappersNeeded);
    wrappers = (wrappers % wrappersNeeded) + freeChocolates;
    chocolates += freeChocolates;
  }

  return chocolates;
}
