// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

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
  const arr: number[] = readNumbers();
  arr.sort((a, b) => a - b);
  cutTheSticks(arr).forEach((x) => console.log(x));
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

function cutTheSticks(arr: number[]): number[] {
  const res: number[] = [];
  for (let i = 0, n = arr.length; i < n; ) {
    res.push(n - i);
    for (const shortest = arr[i]; i < n && arr[i] === shortest; i++);
  }
  return res;
}
