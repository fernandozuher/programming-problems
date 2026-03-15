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
  for (const q of queries(arr, nRotation, nQueries)) console.log(q);
}

function readNumbers(): number[] {
  return readLine().split(' ').map(Number);
}

// T: O(nQueries)
// S: O(1) extra space
function* queries(
  arr: number[],
  nRotation: number,
  nQueries: number,
): Generator<number | undefined> {
  const offset: number = nRotation % arr.length;
  for (let i = 0; i < nQueries; i++) {
    const query = +readLine();
    yield arr.at(query - offset);
  }
}
