// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

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
  for (const x of sequenceEquation(arr)) console.log(x);
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

// n: length of arr
// T: O(n)
// S: O(n) extra space
function* sequenceEquation(arr: number[]): Generator<number | undefined> {
  const valuesToIndex: number[] = Array(arr.length).fill(0);
  let i = 0;
  for (const val of arr) valuesToIndex[val - 1] = i++;
  for (const val of valuesToIndex) yield valuesToIndex[val] + 1;
}
