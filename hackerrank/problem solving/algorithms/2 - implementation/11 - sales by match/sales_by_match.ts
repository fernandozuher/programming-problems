// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

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
  readLine();
  const sockCounts: Map<number, number> = readNumbersIntoMap();
  console.log(sockMerchant(sockCounts));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function readNumbersIntoMap(): Map<number, number> {
  const numberCounts = new Map<number, number>();
  readLine()
    .split(' ')
    .map(Number)
    .forEach((x) => numberCounts.set(x, (numberCounts.get(x) || 0) + 1));
  return numberCounts;
}

function sockMerchant(sockCounts: Map<number, number>): number {
  return Array.from(sockCounts.values()).reduce(
    (pairs, count) => pairs + Math.trunc(count / 2),
    0,
  );
}
