// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

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
  const [price, discount, minPrice, budget]: number[] = readNumbers();
  console.log(howManyGamesCanBeBought(price, discount, minPrice, budget));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function howManyGamesCanBeBought(
  price: number,
  discount: number,
  minPrice: number,
  budget: number,
): number {
  let count = 0;
  while (budget >= price) {
    count++;
    budget -= price;
    price = Math.max(price - discount, minPrice);
  }
  return count;
}
