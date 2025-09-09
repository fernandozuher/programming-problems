// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

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
  Array(n)
    .fill(0)
    .map(() => findDigits(+readLine()))
    .forEach((x) => console.log(x));
}

function findDigits(n: number): number {
  return n
    .toString()
    .split('')
    .map(Number)
    .filter((d) => d !== 0 && n % d === 0).length;
}
