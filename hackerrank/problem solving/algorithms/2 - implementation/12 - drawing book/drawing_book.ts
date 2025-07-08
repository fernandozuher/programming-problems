// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

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

////////////////////////////////////////////////

function main() {
  const n: number = +readLine();
  const page: number = +readLine();
  console.log(pageCount(n, page));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function pageCount(n: number, page: number): number {
  const fromFront: number = Math.trunc(page / 2);
  const fromBack: number = Math.trunc(n / 2) - fromFront;
  return Math.min(fromFront, fromBack);
}
