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

function readLine(): string {
  return inputLines[currentLine++];
}

//////////////////////////////////////////////////

function main() {
  const n: number = +readLine();
  for (let i = 0; i < n; i++) {
    const [prisoners, sweets, startChair] = readNumbers();
    console.log(saveThePrisoner(prisoners, sweets, startChair));
  }
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

// T: O(1)
// S: O(1) extra space
function saveThePrisoner(
  prisoners: number,
  sweets: number,
  startChair: number,
): number {
  return ((startChair - 1 + sweets - 1) % prisoners) + 1;
}
