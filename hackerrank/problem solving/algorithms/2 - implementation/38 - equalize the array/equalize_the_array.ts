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
  console.log(equalizeArray(readNumbers()));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function equalizeArray(arr: number[]): number {
  const counts = counter(arr);
  const maxCount = Math.max(...Object.values(counts));
  return arr.length - maxCount;
}

function counter(arr: number[]): Record<number, number> {
  let counter: Record<number, number> = {};
  arr.forEach((x) => {
    counter[x] = (counter[x] ?? 0) + 1;
  });
  return counter;
}
