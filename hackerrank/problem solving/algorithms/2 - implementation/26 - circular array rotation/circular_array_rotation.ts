// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

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
  const [_, nRotation, nQueries]: number[] = readNumbers();
  const arr: number[] = readNumbers();
  const queries: number[] = Array.from(
    { length: nQueries },
    (_) => readNumbers()[0],
  );
  printQueries(arr, queries, nRotation);
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function printQueries(arr: number[], queries: number[], nRotation: number) {
  const n: number = arr.length;
  const r: number = nRotation % n;
  for (const q of queries) {
    const idx: number = (q + n - r) % n;
    console.log(arr[idx]);
  }
}
