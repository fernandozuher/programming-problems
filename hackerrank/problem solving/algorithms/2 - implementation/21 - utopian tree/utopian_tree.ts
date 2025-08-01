// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

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
  utopianTree(readNumbers(n)).forEach((x) => console.log(x));
}

function readLine(): string {
  return inputLines[currentLine++];
}

function readNumbers(n: number): number[] {
  return Array(n)
    .fill(0)
    .map((_) => +readLine());
}

function utopianTree(testCases: number[]): number[] {
  return testCases.map(calculateHeight);
}

function calculateHeight(cycles: number): number {
  let height = 1;
  for (let cycle = 1; cycle <= cycles; cycle++)
    height = isCycleHappeningDuringSpring(cycle) ? height * 2 : height + 1;
  return height;
}

function isCycleHappeningDuringSpring(cycle: number): boolean {
  return (cycle & 1) === 1;
}
