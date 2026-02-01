// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

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
  readLine();
  console.log(minDeletionsToEqualize(readNumbers()));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

// n: length of arr, 1 <= n <= 100
// T: O(n) = O(100) = O(1)
// S: O(n) = O(100) = O(1) extra space
function minDeletionsToEqualize(arr: number[]): number {
  return arr.length - Math.max(...Object.values(counter(arr)));
}

function counter(arr: number[]): Record<number, number> {
  let counter: Record<number, number> = {};
  arr.forEach((x) => {
    counter[x] = (counter[x] ?? 0) + 1;
  });
  return counter;
}
