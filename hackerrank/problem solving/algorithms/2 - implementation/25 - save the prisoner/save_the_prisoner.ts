// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

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
  const n: number = +readLine();
  Array.from({ length: n })
    .map((_) => {
      const [prisoners, sweets, startChair] = readNumbers();
      return saveThePrisoner(prisoners, sweets, startChair);
    })
    .forEach((x) => console.log(x));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function saveThePrisoner(
  prisoners: number,
  sweets: number,
  startChair: number,
): number {
  return ((startChair - 1 + sweets - 1) % prisoners) + 1;
}
