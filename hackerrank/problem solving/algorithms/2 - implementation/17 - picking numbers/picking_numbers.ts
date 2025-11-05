// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

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

////////////////////////////////////////////////

function main() {
  readLine();
  console.log(pickingNumbers(readNumbersIntoMap()));
}

function readNumbersIntoMap(): Map<number, number> {
  const arr: number[] = readLine().split(' ').map(Number);
  const counter = new Map<number, number>();
  for (const num of arr)
    counter.set(num, (counter.get(num) || 0) + 1);
  return counter;
}

function pickingNumbers(counter: Map<number, number>): number {
  let maxLen = 0;
  for (const [num, count] of counter) {
    const current: number = count + (counter.get(num + 1) || 0);
    maxLen = Math.max(maxLen, current);
  }
  return maxLen;
}
